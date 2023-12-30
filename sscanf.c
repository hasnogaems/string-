#include "header.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct sscanFlags{
    int d;
} sscanFlags;

int s21sscanf(const char* source, const char *format, ...){
va_list args;

flagscanf sscan_Flags={{0}, 0};

int move_str;
va_start(args, format);
char* tmp;
flagscanf Flagscanf={{0}, 0};
while(*format!='\0'){
    printf("here?\n");
    if(*format=='%'){
        scanfparser_flags(format, &Flagscanf);
        scanfparser_spec(format, &Flagscanf);
        //Flagscanf=scanfparser(format);
        tmp=scanf_concat_type(Flagscanf, args, source);
        //va_arg(args,char*);
        printf("tmp=%s\n", tmp);
        //strcat(, tmp);
        //move_str=strlen(tmp);

        
    }
    format++;


}
printf("Flagscanf:\nbase.integer=%d\nbase.string=%d\nfplus=%d\n", Flagscanf.base.integer, Flagscanf.base.string, Flagscanf.fplus);
//printf("Flagscanf:\nbase->integer=%d\n", Flagscanf.base.integer);
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
void scanfparser_flags(const char *format, flagscanf* Flags){
    format++;
    printf("here?54\n");
    while(*format==' '||*format=='-'||*format=='+'||*format=='#'||*format=='0'){
        switch(*format){
            case' ':
            Flags->fspace=1;
            break;
            case'-':
            Flags->fminus=1;
            break;
            case'+':
            Flags->fplus=1;
            break;
            case'#':
            Flags->fsharp=1;
            break;
            case'0':
            Flags->fzero=1;
            break;
        }
        format++;
    }

}

 void scanfparser_spec(const char *format, flagscanf* Flags){
        
        format++;
        while(*format!='\0'){
            printf("here?:82");
        switch(*format){
            case'[':
                // logic parsing regular
                Flags->regular == NULL;
                break;
            default:
                Flags->base = parser(&format, Flags->base); 
        }
    //format++;


    }
       }      
 
int scanf_write_int(flagscanf Flags, va_list arg, const char* source ){
    int i;
    
    while(*source!='\0'){
        if(*source>=0&&*source<=57){
        i=atoi(source);break;}
        source++;
    }
    
    //x=itoa(va_arg(arg, int), x, 10);
    
    
return i;

}

char* scanf_write_string(flagscanf Flags, va_list arg){
    char s[100];
    char* point=s;
    point=va_arg(arg, char*);
return point;

}

   void* scanf_concat_type(flagscanf Flags, va_list arg, const char* source){
    void* add_this=malloc(10000);
    if(Flags.base.integer==1){
       add_this=(void*)(uintptr_t)scanf_write_int(Flags, arg, source);
    }
    else if(Flags.base.string==1){
        add_this=scanf_write_string(Flags, arg);
    }
    return (void*)add_this; //мы допишем это в str вместо %d
   }


