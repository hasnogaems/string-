#include "header.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
typedef struct sscanFlags{
    int d;
} sscanFlags;

int s21sscanf(const char* source, const char *format, ...){
va_list args;

//flagscanf sscan_Flags={{0}, 0};

va_start(args, format);
// char* s=va_arg(args, char*);
// printf("STRING FROM MAIN=%s\n", s);
// int* x=va_arg(args, int*);
// printf("INT X IN MAIN=%d\n", *x);
//char* tmp; тут неинициализированный указатель вызывал сегу видимо
flagscanf Flagscanf={{0}, 0};
int i=0;
while(*format!='\0'&&*source!='\0'){
    printf("22 here?\n");
    int failed=0;
    while(*format==*source && *source != '%'){
        source++;
        format++;

    }
    if(*format=='%'&&Flagscanf.failed==0){
        format++;
        //Flagscanf=scanfparser_flags(&format); // заполняем от ' ' до 0 почему не растет указатель я разименовываю 1 раз, значит должен расти формат
        set_params(&Flagscanf, &format);
        scanfparser_spec(format, &Flagscanf); // заполняем спецификаторы например d или s
        //Flagscanf=scanfparser(format);
        scanf_concat_type(&Flagscanf, args, &source); //возвращаем то, что мы пишем в переменную,
        //va_arg(args,char*);
 //       printf("tmp=%s\n", tmp);тут неинициализированный указатель вызывал сегу видимо
        //как вообще подставить в функцию имя переменной когда оно само переменная?
        //strcat(, tmp);
        //move_str=strlen(tmp);

        
    }
    format++;
i++;

}
printf("Flagscanf:\nbase.integer=%d\nbase.string=%d\nfplus=%d\n", Flagscanf.base.integer, Flagscanf.base.string, Flagscanf.fplus);
//printf("Flagscanf:\nbase->integer=%d\n", Flagscanf.base.integer);
printf("width=%d", Flagscanf.width);
}

// void scanfparser_spec(const char *format, flagscanf* Flags){
        
//         format++;
//         while(*format!=' '&&*format!='\0'){
//            // printf("here?:");
//         switch(*format){
//             case'[':
//                 // logic parsing regular
//                 Flags->regular == NULL;
//                 break;
//             default:
//                 Flags->base = parser(format); 
//         }
    


//     }
//        } вариант марлена
flagscanf scanfparser_flags(const char** format){
    //(*format)++;
    flagscanf Flags={0};
    
    while(**format==' '||**format=='-'||**format=='+'||**format=='#'||**format=='0'){
        switch(**format){
            case' ':
            Flags.fspace=1;
            break;
            case'-':
            Flags.fminus=1;
            break;
            case'+':
            Flags.fplus=1;
            break;
            case'#':
            Flags.fsharp=1;
            break;
            case'0':
            Flags.fzero=1;
            break;
        }
        (*format)++;
    }
    return Flags;

}

 void scanfparser_spec(const char *format, flagscanf* Flags){
        
        //format++;
        while(*format!='\0'&&*format!='%'&&*format!=' '){
            printf("here?:82");
        switch(*format){
           // case'[':
                // logic parsing regular
                //Flags->regular == NULL;
               // break;
            case 'h':
            Flags->h=1;
            format++;
            break;   
            case 'l':
            if(Flags->l==1){
                Flags->ll=1;
            }
            else{
            Flags->l=1;}
                
            format++;//странно что здесь отрабатывает нормально сдвиг
            break;
            case 'L':
            Flags->L=1;
            format++;
            break;
            default:
                Flags->base = parser(&format, Flags->base); 
        }
    //format++;


    }
       }      
 
int* scanf_write_int(flagscanf* Flags, va_list arg, const char** source, long double* result ){
    Flags->failed=1;
   // int* i=va_arg(arg, int*);// какое будет поведение у  va_arg  если тип аргумента не соответствует, например мы указываем int* а там лежит  char*
   // printf("VALUE OF INT I FROM MAIN=%d\n", *i);
    while(**source==' '||**source=='0')(*source)++;
    int i_i;
    char buffer[1000];
    int count=0;
    char* pbuffer=buffer;
    int is_int=0;//вырастет только если была запись в int
    if(**source=='\0'||**source==' '||(**source>=0&&**source<=57&&**source!=32)){ //это нужно чтобы не двигало курсор если мы пытаемся прочитать строку как d
    while(**source!='\0'&&**source!=' '){
        if(**source>=0&&**source<=57&&**source!=32){
            is_int=1; Flags->failed=0;
            while(**source!=' '&&**source!='\0'&&Flags->width>0){
                *pbuffer=**source;
                pbuffer++;
                (*source)++;
               count++;
               Flags->width--;
            }
            //if(Flags->width>0)buffer[Flags->width]='\0';
            
        i_i=atoi(buffer); //buffer почему-то остается в памяти, поэтому заводим счетчик count и зануляем buffer после atoi
        while(count>0){
            buffer[count]='\0';
            count--;
        }
        printf("WRITTEN INT=%d\n", i_i);
        
        break;}
        
       (*source)++;
        
    }
    }

    if(is_int)*result=i_i;
    
    //printf("INT WRITTEN TO MAIN VAR=%d\n", *i);

    
    //x=itoa(va_arg(arg, int), x, 10);
    
    
//return i;

}

char* scanf_write_string(flagscanf* Flags, va_list arg, const char** source){

    while(**source==' '){
        (*source)++;
    }
    char* variable=va_arg(arg, char*);
    char buffer[300]="11";
    int wcount=0;//счетчик сколько раз мы записали, чтобы отмотать
    while(**source!=' '&&**source!='\0'&&Flags->width>0){ //пишем из source в буфер, а почему нельзя сразу писать в variable?
        variable[wcount]=**source;
        wcount++;
        (*source)++;
        Flags->width--;


    }

    variable[wcount]='\0';
    // while(wcount>=0){
    // variable[wcount]=buffer[wcount];//segfault
    //     wcount--;

    // }
   
    
        printf("\nBUFFER=%s\n", buffer);
        printf("VARIABLE=%s\n", variable);

    
    
return variable;

}

   void scanf_concat_type(flagscanf* Flags, va_list arg, const char** source){
    void* add_this=malloc(10000);
    
    long double* result=calloc(1, sizeof(long double));
    if(Flags->base.integer==1){
       add_this=(void*)scanf_write_int(Flags, arg, source, result);
    }
    if(Flags->base.string==1){
        add_this=scanf_write_string(Flags, arg, source);
    }
    if(Flags->base.decimal_octal_hex==1||Flags->base.p){
        add_this=(void*)scanf_write_decimal_octal_hex(arg, source, Flags, result);
        // printf("ADDTHIS=%d\n", *((int*)add_this)); interesting segfault 
    }
    if(Flags->base.e==1){
        sscanf_write_e(arg, source, Flags, result);
    }
    if(Flags->base.o==1){
        sscanf_write_o(arg, source, Flags, result);
    }
    if(!Flags->base.string&&!Flags->base.e){
     if(Flags->ll){ 
        *(va_arg(arg, long long int *)) = (long long int)*result;}
        else if(Flags->l){*(va_arg(arg, long int *)) = (long int)*result;}
        else if(Flags->h){*(va_arg(arg, short int *))= (short int)*result;}
        else{*(va_arg(arg, int*))=(int)*result;}}
    // if(Flags->base.e)
    // {*(va_arg(arg, float*))=(float)*result;}    

   
    //return (void*)add_this; //мы допишем это в str вместо %d
   }  



int* scanf_write_decimal_octal_hex(va_list arg, const char** source, flagscanf* Flags, long double* result){
    Flags->failed=1;
    //int* variable_adress=va_arg(arg, int*);
    int buffer_integer;
    while(**source==' ')(*source)++;
    char buffer[1000];
    
    
    char* pbuffer=buffer;
    int is_int=0;
    int is_hex=0;
    int is_octal=0;
    int minus=0;
    int count_reverse=0;
    if(**source=='-'){
        minus=1;(*source)++;
    }
    if(**source==' '||(**source>=0&&**source<=57&&**source!=32)){
        Flags->failed=0;
        while(**source!='\0'&&**source!=' '&&is_octal ? **source<'8':1){ //вообще ведь нельзя вставить if в while условие? только через ?
            if(**source>=0&&**source<=57&&is_int_f(**source)){
                if(**source=='0'&&*(*source+1)=='x'){ //priority of * highter than + but not highter than ++ seems like
                is_hex=1;(*source)=(*source)+2;}
                if(**source=='0'&&is_int_f(*(*source)+1)&&!is_hex){
                   // if(**source=='0'&&is_int_f(&((*source)+1))){ почему так нельзя хотел передавать функции указатель на указатель, переделал функцию чтобы брала чар
                is_octal=1;(*source)++;
                }
             if(!is_hex&&!is_octal)is_int=1;//пишем в variable только если флаг поднят, если я сделаю int is_int прямо сдесь это плохо, это значит будет переинициализация каждый цикл или норм и оно не будет нагружать программу и инициализирует только 1 раз?
             while(**source!=' '&&**source!='\0'&&is_octal ? **source<'8':1){
                *pbuffer=**source;
               //cannot do that? (&buffer)++;
               //cannot do that? buffer++;
               //must make char* pbuffer=buffer ?
                (*source)++;
                pbuffer++;
                count_reverse++;

             }
            *pbuffer='\0';
             
            }
        }
 while(count_reverse>0){ //отматываем source назад
(*source)--;
count_reverse--;
pbuffer--;
}
    }
    buffer_integer=atoi(buffer);
    printf("buffer_integer=%d", buffer_integer);
//long long result;
    if(is_hex){
        // char* endptr;
        
        *result = hex_to_dex(buffer, 16, Flags, minus, source);
        // *variable_adress=result;
       
        //*variable_adress=hex_to_dex(buffer, 16, Flags, minus);
    }
    if(is_octal){
       *result=hex_to_dex(buffer, 8, Flags, minus, source);
    }
    if(is_int){
       *result=minus ? -1.0*buffer_integer:1*buffer_integer;
    }
    //  if(Flags->ll){ *(va_arg(arg, long long int *)) = (long long int)result;}
    //     else if(Flags->l){*(va_arg(arg, long int *)) = (long int)result;}
    //     else if(Flags->h){*(va_arg(arg, short int *))= (short int)result;}
    //     else{*(va_arg(arg, int*))=(int)result;}
       

}


void sscanf_write_e(va_list arg, const char** source, flagscanf* Flags, long double* result){
    Flags->failed=1;
    float* variable_address=va_arg(arg, float*);
    float buffer_float;
    
    while(**source==' ')(*source)++;
    char buffer[10000];
    char* pbuffer=buffer;
    number_type type={0};
    // int minus=0;
    if(**source>=0&&**source<=57&&**source!=32){
        Flags->failed=0;
        // if(**source=='-')minus=1;
        while(**source!='\0'&&**source!=' '){
            if(**source=='0'&&*(*source+1)=='x'){
                type.is_hex=1; (*source)=(*source)+2;}//skip 0x to number
            
            if(**source=='0'&&is_int_f(*(*source)+1)){
                type.is_octal=1;(*source)++;
            }
            for(int i=1;*(*source+i)!=32;i++){ //тут если вместо 32 поставить ' ' почему то выкидывает из цикла на одну итерацию позже
                if(*(*source+i)=='e'||*(*source+i)=='E'){
                type.is_scientific=1;printf("is scientific\n");
                
                }
            }
            if(!type.is_hex&&!type.is_octal&&!type.is_scientific)type.is_int=1;
            while(**source!=32){
                *pbuffer=**source;
                (*source)++;
                pbuffer++;
            }
            *pbuffer='\0';
    }
        }
        int integer_from_string=atoi(buffer);
    if(type.is_scientific)
    *variable_address=scientific_to_float(buffer); 
    else{
    *variable_address=a_to_float(buffer);}
    if(Flags->failed==1){
        if((strncmp(*source, "inf", 3)==0) ||
        (strncmp(*source, "INF", 3)==0) ||
        (strncmp(*source, "Inf", 3)==0) ||
        (strncmp(*source, "inF", 3)==0) ||
        (strncmp(*source, "InF", 3)==0) ||
        (strncmp(*source, "iNF", 3)==0))
        {
            *variable_address=INFINITY;
            Flags->failed=0;
            *source += 3;
        }
    if((strncmp(*source, "nan", 3)==0) ||
        (strncmp(*source, "NAN", 3)==0) ||
        (strncmp(*source, "NaN", 3)==0) ||
        (strncmp(*source, "Nan", 3)==0) ||
        (strncmp(*source, "naN", 3)==0) ||
        (strncmp(*source, "nAN", 3)==0) )
        {
            *variable_address=NAN;
            Flags->failed=0;
            *source += 3;
        }    

    } 
    
            
    }


int is_int_f(char c){
    int x=0;
    if(c>=0&&c<=57&&c!=32)
    x=1;
    return x;
}

void sscanf_write_o(va_list arg, const char** source, flagscanf* Flags, long double* result){
     Flags->failed=1;
    int* variable_adress=va_arg(arg, int*);
    int buffer_integer;
    while(**source==' ')(*source)++;
    char buffer[1000];
    
    
    char* pbuffer=buffer;
    int is_int=0;
    int is_hex=0;
    int is_octal=0;
    int minus=0;
    int count_reverse=0;
    if(**source=='-'){
        minus=1;(*source)++;
    }
    if(**source==' '||(**source>=0&&**source<=57&&**source!=32)){
        Flags->failed=0;
        while(**source!='\0'&&**source!=' '&&is_int_f(**source)){
            if(**source>=0&&**source<=57&&is_int_f(**source)){
               
                if(**source=='0'&&is_int_f(*(*source)+1)&&!is_hex){
                   // if(**source=='0'&&is_int_f(&((*source)+1))){ почему так нельзя хотел передавать функции указатель на указатель, переделал функцию чтобы брала чар
                is_octal=1;(*source)++;
                }
             if(!is_hex&&!is_octal)is_int=1;//пишем в variable только если флаг поднят, если я сделаю int is_int прямо сдесь это плохо, это значит будет переинициализация каждый цикл или норм и оно не будет нагружать программу и инициализирует только 1 раз?
             
             while(**source!=' '&&**source!='\0'/*&&is_int_f(**source)*/){
                *pbuffer=**source;
               //cannot do that? (&buffer)++;
               //cannot do that? buffer++;
               //must make char* pbuffer=buffer ?
                (*source)++;
                pbuffer++;
                count_reverse++;
                //count++;

             }
            *pbuffer='\0';
//тут была сега если вставить отмотку сюда, то идет бесконечный цикл и pbuffer растет вплоть до segfault
             
            }
      
        }
              while(count_reverse>0){ //отматываем source назад
(*source)--;
count_reverse--;
pbuffer--;
}

    }
    buffer_integer=atoi(buffer);
    printf("buffer_integer=%d", buffer_integer);

    if(is_hex){
        // char* endptr;
        
        // long int result = strtol(buffer, &endptr, 16);
        // *variable_adress=result;
        *variable_adress=hex_to_dex(buffer, 8, Flags, minus, source);
    }
    if(is_octal){
        *variable_adress=hex_to_dex(buffer, 8, Flags, minus, source);
    }
    if(is_int){
       *variable_adress=hex_to_dex(buffer, 8, Flags, minus, source);
    }
    

}

void width_function(const char **format, int *width) {
   while (**format <= 57 && **format >= 48) {
    *width = *width * 10 + (**format - '0');
    (*format)++;

    
  }

  }

void set_params(flagscanf *Flags, const char **format) {
  width_function(format,  &(Flags->width));
  if (Flags->width == 0) {
    Flags->width = -1;
    Flags->failed = 0;
  }

  
}




