#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

#include "asm.h"

int main(void){
  //FILE *in,*out;
  //fscanf(in, );
  FILE *in,*out;

  if( (in=fopen(FILE_IN,"r")) == NULL ) {
    perror(FILE_IN);
    exit(EXIT_FAILURE);
  }

  if( (out=fopen(FILE_OUT,"w")) == NULL ) {
    perror(FILE_OUT); // perror(char *);!!!
    exit(EXIT_FAILURE);
  }
  
  char debut[MAX_LINE_SIZE] = {};

  while(strcmp(debut,".Lfunc_end0:")) {
    fscanf(in,"%s",debut);
    if(!strcmp(debut,".pad")) {
      fseek(in,4*sizeof(char),1);
      break;
    }
  }

  int label[50];
  int pc = 0;
  enum instruction i;
  while(strcmp(debut,".Lfunc_end0:")){    
    fscanf(in,"%s",debut);
    i = s2e(debut);
    
    if(i != -1) {
      pc++;
      while(fgetc(in) != '\n'){}// next ligne
      continue;
    }
    
    if(strstr(debut,".LBB0_")){
      label[*(debut+6)-'0'] = pc;
    }
  }

  rewind(in);
  debut[0] = '\0';  // init
  
  while(strcmp(debut,".Lfunc_end0:")) {
    
    fscanf(in,"%s",debut);
    if(!strcmp(debut,".pad")) {
      fseek(in,4*sizeof(char),1);
      break;
    }
  }
    
  int addr = 0;
  int num  = 0;

  int r[7] = {0};
  int rn, rd, rdn, rm, rt, imm3, imm5, imm7, imm8, label1;
  
  Inst_shift order_lla;
  Inst_ASA order_asa;
  Inst_Movs order_movs;
  Inst_data order_data;
  Inst_load order_load;
  Inst_stack order_stack;
  Inst_branch order_b;

  enum instruction inst;

  fprintf(out,"v2.0 raw\n");
  
  while(strcmp(debut,".Lfunc_end0:")){
    fscanf(in,"%s",debut);
    inst = s2e(debut);
    
    switch(inst){
    case lsls :
    case lsrs :
    case asrs :
      //fprintf(out,"%s",debut);
      if ((num = fscanf(in,"\tr%d, r%d, #%d\n",&rd,&rm,&imm5)) == 3){ // !!\n
       
	order_lla.idcode = 0;
	order_lla.opcode = inst;
	order_lla.rd = rd;
	order_lla.rm = rm;
	order_lla.imm5 = imm5;
	addr++;
	
	fprintf(out,"%04hx ",order_lla);
	
      }
      else if( num == 2 ){
	order_data.idcode = 16;
	order_data.opcode = inst + 2;  // lsls_imm == 0, lsls == 2
	order_data.rdn = rd;
	order_data.rm  = rm;
	addr++;
	fprintf(out,"%04hx ",order_data);
      }
      break;
      
    case adds :
    case subs :
      //fprintf(out,"%s",debut);
      
      fscanf(in,"\tr%d, r%d, ",&rd,&rn);
      if(fscanf(in,"#%d\n",&imm3) > 0){
	r[rd] = r[rn] + ( inst == adds ? imm3 : -imm3 ); // adds et subs

	order_asa.idcode = 0;
	order_asa.opcode = inst + 11; //adds == 3,adds_imm_opcode = 14
	order_asa.rd = rd;
	order_asa.rn = rn;
	order_asa.rm_imm = imm3;
	addr++;
	
	fprintf(out,"%04hx ",order_asa);
	
      }
      else if( fscanf(in,"r%d\n",&rm) > 0){
	r[rd] = r[rn] + ( inst == adds ? r[rm] : -r[rm] ); // adds et subs
	
	order_asa.idcode = 0;
	order_asa.opcode = inst + 9; //adds == 3,adds_opcode = 12
	order_asa.rd = rd;
	order_asa.rn = rn;
	order_asa.rm_imm = rm;
	addr++;
	fprintf(out,"%04hx ",order_asa);
      }
      break;
    case movs :
      //fprintf(out,"%s",debut);
      
      if ( fscanf(in,"\tr%d, #%d\n",&rd, &imm8) > 0){
	r[rd] = imm8;
	
	order_movs.idcode = 0;
	order_movs.opcode = 4; 
	order_movs.rd = rd;
	order_movs.imm8 = imm8; 
	addr++;
	
	fprintf(out,"%04hx ",order_movs);
	
      }
      
      break;

    case ands:
    case eors:
    case adcs :
    case sbcs :
    case rors :
    case tst :
    case rsbs : // problem
    case cmp :
    case cmn :
    case orrs :
    case muls : // problem
    case bics :
    case mvns :
      //fprintf(out,"%s",debut);
      if ((num = fscanf(in,"\tr%d, r%d\n",&rdn,&rm) ) == 2){
	order_data.idcode = 16;
	order_data.opcode = inst - ands;  // !!!!!!!!!!!!and == 6
	order_data.rdn = rdn;
	order_data.rm  = rm;
	addr++;
	fprintf(out,"%04hx ",order_data);
      }
      break;
     
    case str :
    case ldr :
      //fprintf(out,"%s",debut);
      if ((num = fscanf(in,"\tr%d, [sp, #%d]\n",&rt, &imm8) ) == 2){
	
	order_load.idcode = 9;
	order_load.opcode = (inst == str ? 0 : 1);
	order_load.rt = rt;
	order_load.imm8  = imm8;
	addr++;
	fprintf(out,"%04hx ",order_load);
      }
      else if(num == 1){
	
	order_load.idcode = 9;
	order_load.opcode = (inst == str ? 0 : 1);
	order_load.rt = rt;
	order_load.imm8  = 0;
	addr++;
	fprintf(out,"%04hx ",order_load);
      }
      break;
      
    case add :
    case sub :
      //fprintf(out,"%s",debut);
      if ((num = fscanf(in,"\tsp, #%d\n",&imm7) ) > 0){
	
	order_stack.idcode = 11;
	order_stack.opcode = (inst == add ? 0 : 1);
	order_stack.imm7  = imm7;
	addr++;
	fprintf(out,"%04hx ",order_stack);
      }
      break;
    case beq :
    case bne :
    case bcs :
    case bcc :
    case bmi :
    case bpl :
    case bvs :
    case bvc :
    case bhi :
    case bls :
    case bge :
    case blt :
    case bgt :
    case ble :
    case b :
      //case bal : bal == b
      //fprintf(out,"%s",debut);
      if ((num = fscanf(in,"\t.LBB0_%d\n",&label1) ) > 0){
	
	order_b.idcode = 13;
	order_b.cond = inst - beq;
	imm8 =   -((addr - label[label1]) + 3);
	order_b.imm8  = imm8;
	addr++;
	
	//!!!!!!!!!! label - addr???  b .lbb0_1 imm8 == -2
	//fprintf(out,"\n %s\t.LBB0_%d\n",debut, label1);
	//fprintf(out,"imm8 == addr:%d - label:%d\n imm8=%d",addr,label[label1],order_b.imm8);
	
	fprintf(out,"%04hx ",order_b);
      }
      break;
    default : break;
    }
  }

  if(strcmp(debut,".Lfunc_end0:")){
    printf("2");
    perror("NOT A .s FILE");
    exit(EXIT_FAILURE);
  }
  
  fclose(in);  fclose(out);
  
  return EXIT_SUCCESS;
}



enum instruction s2e(char* inst)
{
    if(strcmp(inst, "lsls")==0) return lsls;
    if(strcmp(inst, "lsrs")==0) return lsrs;
    if(strcmp(inst, "asrs")==0) return asrs;
    
    if(strcmp(inst, "adds")==0) return adds;
    if(strcmp(inst, "subs")==0) return subs;
    if(strcmp(inst, "movs")==0) return movs;
    if(strcmp(inst, "ands")==0) return ands;
    if(strcmp(inst, "eors")==0) return eors;
    if(strcmp(inst, "adcs")==0) return adcs;
    if(strcmp(inst, "sbcs")==0) return sbcs;
    if(strcmp(inst, "rors")==0) return rors;
    if(strcmp(inst, "tst")==0) return tst;
    if(strcmp(inst, "rsbs")==0) return rsbs;
    if(strcmp(inst, "cmp")==0) return cmp;
    if(strcmp(inst, "cmn")==0) return cmn;
    if(strcmp(inst, "orrs")==0) return orrs;
    if(strcmp(inst, "muls")==0) return muls;
    if(strcmp(inst, "bics")==0) return bics;
    if(strcmp(inst, "mvns")==0) return mvns;
    if(strcmp(inst, "str")==0) return str;
    if(strcmp(inst, "ldr")==0) return ldr;
    if(strcmp(inst, "add")==0) return add;
    if(strcmp(inst, "sub")==0) return sub;
    if(strcmp(inst, "beq")==0) return beq;
    if(strcmp(inst, "bne")==0) return bne;
    if(strcmp(inst, "bcs")==0) return bcs;
    if(strcmp(inst, "bcc")==0) return bcc;
    if(strcmp(inst, "bmi")==0) return bmi;
    if(strcmp(inst, "bpl")==0) return bpl;
    if(strcmp(inst, "bvs")==0) return bvs;
    if(strcmp(inst, "bvc")==0) return bvc;
    if(strcmp(inst, "bhi")==0) return bhi;
    if(strcmp(inst, "bls")==0) return bls;
    if(strcmp(inst, "bge")==0) return bge;
    if(strcmp(inst, "blt")==0) return blt;
    if(strcmp(inst, "bgt")==0) return bgt;
    if(strcmp(inst, "ble")==0) return ble;
    if(strcmp(inst, "b")==0) return b;
    if(strcmp(inst, "bal")==0) return bal;
    
    return -1;
} 