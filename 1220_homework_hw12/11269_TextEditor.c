#include <stdio.h>
#include <string.h>

#define MAX_SIZE 520

char content[MAX_SIZE];
char input[MAX_SIZE];

int main()
{

    fgets(input, MAX_SIZE, stdin);
    int i = 0;
    int cursor = 0;
    int mode = 0;
    while(input[i] != '\0')
    {
        char c = input[i];
        if(mode == 0)
        {
            if(c == '/')
                mode = 1;
            else if(cursor < strlen(content)-1)
            {
                int len = strlen(content);
                for (int j = len;j>cursor;j--)
                {
                    content[j] = content[j-1];
                }
                content[cursor] = c;
                cursor++;
            }
            else
            {
                content[cursor] = c;
                cursor++;
            }
        }
        else if(mode == 1)
        {
            if(c == 'b')
            {
                if(cursor == 0)
                    cursor = 0;
                else
                {
                    int len = strlen(content);
                    if(cursor < len-1)
                    {
                        for (int j = cursor;j<len;j++)
                        {
                            content[j-1] = content[j];
                        }
                    }
                    else
                    {
                        content[cursor-1] = '\0';
                    }
                }
                if(cursor == 0)
                    cursor = 0;
                else
                    cursor--;
                i += 8;
                mode = 0;
            }
            else if(c == 'n')
            {
                int len = strlen(content);
                if(cursor < len-1)
                {
                    for (int j = len;j>cursor;j--)
                    {
                        content[j] = content[j-1];
                    }
                    content[cursor] = '\n';
                }
                else 
                {
                    content[cursor] = '\n';
                }
                cursor++;
                i += 6;
                mode = 0;
            }
            else if(c == 'l')
            {
                if(cursor == 0)
                    cursor = 0;
                else
                    cursor --;
                i += 3;
                mode = 0;
            }
            else if(c == 'r')
            {
                int len = strlen(content);
                if(cursor < len-1)
                    cursor++;
                else 
                    cursor = len-1;
                i += 4;
                mode = 0;
            }
        }
        i++;
    }
    printf("%s", content);

    return 0;
}