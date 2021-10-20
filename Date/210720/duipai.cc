#include<iostream>
using namespace std;
int main(){
    int i;
  for (i=1;;i++){
        printf("The result of No. %d Case is:  ",i);
        system("./data > data.txt");
        system("./k <data.txt >test.txt");
        system("./check <test.txt >is.txt");
        if (system("diff is.txt ok.txt")){
            printf("Wrong Answer\n");
            return 0;
        }
        else printf("Accepted\n");
    }
    return 0;
}
