// @JUDGE_ID:  17051CA  10476  C++
// @begin_of_source_code
/* Calculation */
#include<stdio.h>
#include<iostream>
#include<map>
#include<string>

class SpamOrNotSpam{
 public:
  map<string, int> spamM;
  map<string, int> notSpamM;
  map<string, int> messageM;
  int nmessage;
  double rootSumS, rootSumN, rootSumM;

  double similarity( map<string, int> &f1, map<string, int> &f2 ){

    map<string, int>::iterator pos;
    
    double numerator, denominator1, denominator2;

    numerator = denominator1 = denominator2 = 0;

    for ( pos = f1.begin(); pos != f1.end(); pos++ ){
      int f1t = (*pos).second;
      int f2t = f2[ (*pos).first ];
      numerator += (double)(f1t*f2t);
    }

    for ( pos = f1.begin(); pos != f1.end(); pos++ ){
      int t = (*pos).second;
      denominator1 += (double)(t*t);
    }

    for ( pos = f2.begin(); pos != f2.end(); pos++ ){
      int t = (*pos).second;
      denominator2 += (double)(t*t);
    }
    
    denominator1 = sqrt( denominator1 );
    denominator2 = sqrt( denominator2 );

    return numerator / ( denominator1 * denominator2 );
  }

  void compute(){
    double similarityMS, similarityMN;
    similarityMS = similarity( messageM, spamM );
    similarityMN = similarity( messageM, notSpamM );

    printf("%.5lf %.5lf\n", similarityMS, similarityMN );
    if ( similarityMS > similarityMN ){
      printf("spam\n");
    } else {
      printf("non-spam\n");
    }
  }

  void work(){
    string str;
    for ( int i = 0; i < nmessage; i++ ){
      messageM.clear();
      while ( 1 ){
	getline( cin, str );
	if ( str == "ENDMESSAGE") break;
	addMessageTrigram( str );
      }
      compute();
    }
  }

  void init(){
    spamM.clear();
    notSpamM.clear();
    messageM.clear();
  }

  void addSpamTrigram( string str ){
    if ( str.size() < 3 ) return;
    for ( int i = 0; i <= str.size() - 3; i++ ){
      spamM[ str.substr(i, 3 ) ]++;
    }
  }

  void addNotSpamTrigram( string str ){
    if ( str.size() < 3 ) return;
    for ( int i = 0; i <= str.size() - 3; i++ ){
      notSpamM[ str.substr(i, 3 ) ]++;
    }
  }

  void addMessageTrigram( string str ){
    if ( str.size() < 3 ) return;
    for ( int i = 0; i <= str.size() - 3; i++ ){
      messageM[ str.substr(i, 3 ) ]++;
    }
  }

  string readMessage(){
    string line;
    string str = "";
    while ( 1 ){
      getline( cin, line );
      if ( line == "ENDMESSAGE" ) break;
      str += line;
    }
    return str;
  }

  bool read(){
    init();
    int s, n;
    string str;
    cin >> s >> n >> nmessage;
    if ( s == 0 && n == 0 && nmessage == 0 ) return false;
    getline( cin, str );

    for ( int i = 0; i < s; i++ ){
      while ( 1 ){
	getline( cin, str );
	if ( str == "ENDMESSAGE") break;
	addSpamTrigram( str );
      }

    }
    
    for ( int i = 0; i < n; i++ ){
      while ( 1 ){
	getline( cin, str );
	if ( str == "ENDMESSAGE") break;
	addNotSpamTrigram( str );
      }
    }

    return true;
  }
};

main(){
  SpamOrNotSpam SONS;
  
  for ( int i = 1;  SONS.read(); i++ ){
    printf("Set %d:\n", i );
    SONS.work();
  }
}

// @end_of_source_code


