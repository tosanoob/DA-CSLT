#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <errno.h>
using namespace std;

int main()
{
        ifstream inp("inputuser.txt");
        int a;
        char dir_name[20] = "tempfile";

        DIR *check = opendir(dir_name);
        if (check) //directory existed
        {
                a = chdir("E:/ITProject/C_CPP/DACSLT2/tempfile");
                if (a == -1)
                {
                        cout << "Change directory failed";
                        return 1;
                }
        }
        else if (ENOENT == errno) //directory is not exist;
        {
                a = mkdir(dir_name);
                if (a == -1)
                {
                        cout << "Make directory failed";
                        return 2;
                }
        } 
        else {
                cout<<"Unknown error occured";
                return -1;
        }

        ofstream dest[10];
        for (int i = 0; i < 5; i++)
        {
                char temp[20] = "";
                char dir[20];
                strcpy(dir,dir_name);
                itoa(i, temp, 5);
                cout<<temp<<'\n';
                strcpy(temp, strcat(dir, temp));
                dest[i] = ofstream(temp);
        }

        for (int i = 0; i < 5; i++)
        {
                dest[i] << inp.rdbuf(); //đọc toàn bộ file inp chép vào dest[i]
                //khi kết thúc con trỏ nằm cuối file
                inp.seekg(ios::beg); //đưa con trỏ đọc về đầu file: seekget -> begin
                dest[i].close();
        }

        cout << "Write temp success\n";
        inp.close();

        return 0;
}