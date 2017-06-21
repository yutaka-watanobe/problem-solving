// @JUDGE_ID:  17051CA  506  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stl.h>

class System{
 public:
  map<string, vector<string> > DP; /* dependencies map */
  vector<string> IL; /* installed list */
  map<string, bool> U; /* is installed ? */
  map<string, int> DC; /* depended counter */
  map<string, bool> UI; /* user installed */
  
  System(){}

  void depend( string item, vector<string> &v ){
    for ( int i = 2; i < v.size(); i++ ){
      DP[ item ].push_back( v[i] );
      DC[ item ] = 0;
    }
  }

  void install_parent( string item ){
    vector<string> depended_items = DP[ item ];
    for ( int i = 0; i < depended_items.size(); i++ ){
      string parent = depended_items[i];
      if ( U[ parent ] ){
	DC[ parent ]++;
      } else {
	install_parent( parent );
      }
    }
    U[ item ] = true;
    UI[ item ] = false;
    DC[ item ]++;
    IL.push_back( item );
    cout << "   Installing " << item << endl;
  }

  void install( string item ){
    if ( U[ item ] ){
      cout << "   " << item << " is already installed." << endl;
      return;
    }

    vector<string> depended_items = DP[ item ];
    for ( int i = 0; i < depended_items.size(); i++ ){
      string parent = depended_items[i];
      if ( U[ parent ] ){
	DC[ parent ]++;
      } else {
	install_parent( parent );
      }
    }
    U[ item ] = true;
    UI[ item ] = true;

    IL.push_back( item );
    cout << "   Installing " << item << endl;
  }

  void remove( string item ){
    if ( !U[ item ] ){
      cout << "   " << item << " is not installed." << endl;
      return;
    }
    if ( DC[ item ] != 0 ){
      cout << "   " << item << " is still needed." << endl;
      return;
    }

    remove_item( item );

    vector<string> depended_items = DP[ item ];
    for ( int i = 0; i < depended_items.size(); i++ ){
      string parent = depended_items[i];
      DC[ parent ]--;
      if ( DC[ parent ] == 0 && !UI[ parent ] ){
	remove_parent( parent );
      }
    }

  }

  void remove_parent( string item ){
    remove_item( item );
    vector<string> depended_items = DP[ item ];
    for ( int i = 0; i < depended_items.size(); i++ ){
      string parent = depended_items[i];
      DC[ parent ]--;
      if ( DC[ parent ] == 0 && !UI[ parent ] ){
	remove_parent( parent );
      }
    }

  }

  void remove_item( string item ){
    for ( int i = 0; i < IL.size(); i++ ){
      if ( IL[i] == item ){
	IL.erase( IL.begin() + i );
	break;
      }
    }
    U[ item ] = false;    
    cout << "   Removing " << item << endl;
  }

  void listUp(){
    for ( int i = 0; i < IL.size(); i++ ){
      cout << "   " << IL[i] << endl;
    }
  }
};

/*
 * stringオブジェクトを1文字のデリミタ(デフォルトは空白)で区切る
 * 要件: #include <string>, #include <stl.h>
 */
void split(vector<string> &d, const string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

main(){
  System system = System();
  string line, command;
  vector<string> v;
  while ( 1 ){
    getline( cin, line );
    if ( line.size() == 0 ) continue;
    cout << line << endl; /* echo */
    v.clear();
    split( v, line );
    command = v[0];
    if ( command == "DEPEND" ){
      system.depend( v[1], v );
    } else if ( command == "INSTALL" ){
      system.install( v[1] );
    } else if ( command == "REMOVE" ){
      system.remove( v[1] );
    } else if ( command == "LIST" ){
      system.listUp();
    } else if ( command == "END" ){
      break;
    }
  }
}
// @end_of_source_code
