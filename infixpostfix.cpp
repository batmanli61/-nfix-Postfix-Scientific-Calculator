#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;

void isaretlerkoy(char);
int oncelik(char);
void tasi();
int hata(int );

char infix[50],postfix[50],isaretler[50];
int isaretust=-1;
int j=0;

int main(int argc, char *argv[])
{int oncelik1,oncelik2,eror;
char ch;
ifstream oku_dosya;
string dosyaadresi;
    cout<<"Infix ifadeyi dosyadan alacaksaniz d'ye basin..."<<endl<<endl;
    cout<<"Infix ifadeyi siz girecekseniz i'ye basin."<<endl<<"ardindan yanina denklemi yaziniz:"<<endl<<endl;
    cin>>ch;
   

  for(int i=0;i<50;i++){                       //diziler NULL yapýldý.
             postfix[i]=0;
             isaretler[i]=0;
             }  
    x:
         if(ch=='d'){               //dosyadan okunacaksa bu bölümde okuma yapýlýr.
              cout<<"dosya ismi girin:"<<endl;
                 cin>>dosyaadresi;  
                   oku_dosya.open(dosyaadresi.c_str()); 
                   while((oku_dosya>>infix));
      oku_dosya.close(); 
                     }  
         else {       //denklem elle girilecekse burda girilir.
              cout<<endl;
              gets(infix);
              cout<<endl;
                }   
       
                        


        for(int i=0;infix[i]!=0;i++){
                                 
                                 eror=hata(i);             //denklemdeki hatalarý tespit eder.
                                 if(eror==1)
                                 goto x;
                      
              if(infix[i]!='('&&infix[i]!=')'&&infix[i]!='/'&&infix[i]!='*'&&infix[i]!='+'&&infix[i]!='-'&&infix[i]!='^')
                        postfix[j++]=infix[i];
               else if(infix[i]=='(')                       //aç parantez yerleþtirmesi
                        isaretlerkoy(infix[i]);
               else if(infix[i]==')'){                     //kapa parantez yerleþtirmesi
                          while(isaretler[isaretust]!='('){
                            isaretust=isaretust-1;                               
                          postfix[j++]=isaretler[isaretust+1];
                                                           }
                          isaretust--;
                                        }                   //kapa parantez yerleþti                      
                                           
                else{                                 //aritmetik iþlem elemaný yerleþtirmesi                         
                          oncelik1=oncelik(infix[i]);
                          
                          if(isaretust!=-1){
                          oncelik2=oncelik(isaretler[isaretust]);}   
                          else
                          oncelik2=0;            
                                       if(oncelik1>oncelik2)
                                           isaretlerkoy(infix[i]);
                          
                                       else{
                                            
                                            while(oncelik1<=oncelik2){
                                                                      
                                                                      if(isaretust==-1)
                                                                      break;
                                                                      else{
                                                                       tasi();
                                                                        oncelik2=0;  
                                                                        }
                                                                           
                                                                        }    
                                                       isaretlerkoy(infix[i]);    
                                            }
                           }                                 //iþlem yerleþtirmesi biter.
                       } 
       
       for(int i=0;i<=isaretust;i++){       //denklem bitince isaretler dizisindeki elemanlarý postfix'e aktarýr
                           postfix[j++]=isaretler[i];
                            
                            } 
                            
                            cout<<endl<<"postfix:";    //--postfix'i ekrana yazdýrýr.
                    for(int i=0;i<50;i++){
                            if(postfix[i]!='(')
                    cout<<postfix[i];     
                    }
                    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
//----------------------------------------------------------------------------------------------------------------------
void isaretlerkoy(char krk){
        if(isaretust!=49){
                          isaretust++;
                          isaretler[isaretust]=krk;
                          } 
                        }
//-----------------------------------------------------------------------------------------------------------------------
int oncelik(char krk){
               if(krk=='^') return 4;    
          else if(krk=='*'||krk=='/') return 3;     
          else if(krk=='+'||krk=='-') return 2;         
else if(krk==')'||krk=='(') return 1;
                      }
//------------------------------------------------------------------------------------------------------------------------
void tasi(){
     while(isaretust!=-1){
     postfix[j++]=isaretler[isaretust--];
                         }
            }
//-------------------------------------------------------------------------------------------------------------------------
 int hata(int i){
     if(infix[i]=='('&&infix[i+1]==')'){
                                         cout<<"parantez hatasi yaptiniz."<<i+2<<". denklem elemanini kontrol ediniz."<<endl;
                                         return 1;
                                         }
      if(infix[i]=='('&&infix[i+1]!=')'){
                                      if(infix[i+1]=='/'||infix[i+1]=='*'||infix[i+1]=='-'||infix[i+1]=='+'||infix[i+1]=='^'){
                                         cout<<"isaret hatasi yaptiniz."<<i+2<<". denklem elemanini kontrol ediniz."<<endl;
                                         return 1;
                                                                                                                              }   
                                         }
      if(infix[i]=='('){
           if(infix[i]!='('&&infix[i]!=')'&&infix[i]!='/'&&infix[i]!='*'&&infix[i]!='+'&&infix[i]!='-'&&infix[i]!='^'){
                cout<<"parantez hatasi yaptiniz."<<i<<". denklem elamanini kontrol ediniz."<<endl;
                          return 1;
                                                                                                                     }
                                       }
      
      if(infix[i]=='/'||infix[i]=='*'||infix[i]=='+'||infix[i]=='-'){
                                                                     if(infix[i+1]==')'){
         cout<<"parantez hatasi yaptiniz."<<i+2<<". denklem elemanini  kontrol ediniz."<<endl;
                                         return 1;
                                         }
                                                                     }
           if(infix[i]=='/'||infix[i]=='*'||infix[i]=='+'||infix[i]=='-'){
               if(infix[i+1]=='/'||infix[i+1]=='*'||infix[i+1]=='+'||infix[i+1]=='-'){
                 cout<<"isaret hatasi yaptiniz.Ard arda iki isaret gelemez."<<i+2<<". denklem elemanini kontrol ediniz."<<endl;
                                                                                return 1;
                                                                                      }
                                                                          }                                                          
      return 0;                                   
     }  
     
     
         
                    
 
