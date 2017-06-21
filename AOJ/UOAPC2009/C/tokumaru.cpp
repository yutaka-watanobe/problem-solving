
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdlib>
using namespace std;

void a(int*);
void e(string*,int*,int*);
void p(int*,int*);
void n(int*,int*,int);
void f(string*,int*,int*,int);
void b(string*,int*,int*);
void d(string*,int*,int*,int*);
void k(string*,int*,int*,int*,char*);
void y(string*,int*,int*,int*,char*);





int main(void){
  
  string itext[200];
  char baf[2000];
  int cur=0,line=0,max_line=0;
  baf[0]='\0';
  for(int i=0;;i++){
    getline(cin,itext[i]);
    if(itext[i]=="END_OF_TEXT")break;
    max_line++;
  }
  itext[max_line].clear();
  max_line--;
   char com;
  while(1){
    cin>>com;
    if(com=='a')a(&cur);
    if(com=='e')e(itext,&cur,&line);
    if(com=='p')p(&cur,&line);
    if(com=='n')n(&cur,&line,max_line);
    if(com=='f')f(itext,&cur,&line,max_line);
    if(com=='b')b(itext,&cur,&line);
    if(com=='d')d(itext,&cur,&line,&max_line);
    if(com=='k')k(itext,&cur,&line,&max_line,baf);
    if(com=='y')y(itext,&cur,&line,&max_line,baf);
    if(com=='-')break;
    /**

    for(int i2=0;i2<=max_line;i2++){
      cout<<itext[i2]<<endl;
    }
    
    cout<<"cur:"<<cur<<" line:"<<line<<" baf:"<<baf<<endl;
    **/
  }
  int i=0;
  //cout<<max_line<<endl;
  if(max_line==-1)printf("\n");
  for(i=0;i<=max_line;i++){
    cout<<itext[i]<<endl;
  }
  return 0;
}

void a(int *cur){
  *cur=0;
}

void e(string *itext,int *cur,int *line){
  *cur=itext[*line].length();
}

void p(int *cur,int *line){
  if(*line>0)*line=*line-1;
  *cur=0;
}

void n(int *cur,int *line,int max_line){
  if(*line < max_line)*line=*line+1;
  *cur=0;
}

void f(string *itext,int *cur,int *line,int max_line){
  if(itext[*line].length()!=*cur)*cur=*cur+1;
  else if((itext[*line].length()==*cur) &&( *line < max_line)){
    *line=*line+1;
    *cur=0;
  } 
}

void b(string *itext,int *cur,int *line){
  if(*cur!=0)*cur=*cur-1;
  else if(*cur==0&&*line>0){
    *line=*line-1;
    *cur=itext[*line].length();
  }  
}
void d(string *itext,int *cur,int *line,int *max_line){
  if(itext[*line].length()!=*cur){
    itext[*line].erase(*cur,1);
   }else if(itext[*line].length()==*cur && *line < *max_line){
     itext[*line].insert(*cur,itext[*line+1],0,itext[*line+1].length());
    for(int i=*line+1;i<=*max_line;i++){
      if(i<*max_line)itext[i]=itext[i+1];
      if(i==*max_line){
	itext[i].clear();
	*max_line=*max_line-1;
      }
    }
  }
}
void k(string *itext,int *cur,int *line,int *max_line,char *baf){
  if(itext[*line].length()==*cur && *line<*max_line){
    d(itext,cur,line,max_line);
    sprintf(baf,"\n");
   }else if(itext[*line].length()!=*cur){
    string temp;
    char text[2000];
    temp =itext[*line].substr(*cur,itext[*line].length()-*cur);
    for(int i=0;i<temp.length();i++){
      text[i]=temp[i];
      if(i==temp.length()-1)text[i+1]='\0';
    }
    itext[*line].erase(*cur,itext[*line].length()-*cur);
    sprintf(baf,"%s",text);
    *cur=itext[*line].length();
  }
  
}

void y(string *itext,int *cur,int *line,int *max_line,char *baf){
  string temp;
  temp=baf;

  if(!temp.empty()){
    if(temp=="\n"){
     for(int i=*max_line+1;i>*line;i--){
	itext[i] = itext[i-1];
      }
      *max_line=*max_line+1;
      itext[*line+1] = itext[*line].substr(*cur,itext[*line].length()-(*cur-1));
      itext[*line].erase(*cur,itext[*line].length()-(*cur-1));
    }else if(baf[0]!='\0'){
      itext[*line].insert(*cur,temp);
      *cur=*cur+temp.length();
    }
  }
}

