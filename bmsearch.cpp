/**
* Simplified Boyer-Moore search
*
* Tell you if your pattern contains in a string
*
*
*
*/

#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;
int BMSearch(char *str, char *pat){
  int n = strlen(str);
  int m = strlen(pat);
  int  i;
  int  TAB[256];
  for (i = 0; i < 256; ++i)
    TAB[i] = m;
  for (i = 0; i < m - 1; ++i)
    TAB[pat[i]] = m - 1 - i;
  
  int j = 0; i = 0;
  int s = i = j = m - 1;
  while(j > 0 && i < n) {
      if(str[i] != pat[j]) {
        i += TAB[str[i]];
        j = s;
      }
      else{
        i--;
        j--;
    }
  }
   if(j == 0)
    return j;
   else
    return -1;
}
int main(){
  char string[30];
  char substring[30];
  cout << "Enter string" << endl;
  gets(string);
  cout << "Enter substring" << endl;
  gets(substring);
  int res = BMSearch(string, substring);
  if (res == 0)
    cout << "Substring found" << endl;
  else
    cout << "Substring not found " << endl;
  getch();
  return 0;
}