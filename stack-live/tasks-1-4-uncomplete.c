 /* A simple calculator - Task 1 and Task 2 and ***(2) Enhancing the calculator*** */

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 25

void read_user_input(char*buffer)
{
  fgets(buffer, MAXSIZE, stdin);
}

void print_user_input(char*buffer)
{
  printf("%s\n",buffer);
}

/*This function compare the '*' and '+' to decide the priority*/
int has_priority(char op1, char op2)
{
  if (op1=='*' || op1=='/')
  {
    printf("%c > %c\n", op1, op2);
    return 1;
  }

  if ((op1=='+' || op1=='-') && (op2=='+' || op2=='-'))
  {
    printf("%c > %c\n", op1, op2);
    return 1;
  }

  printf("%c < %c\n", op1, op2);
  return 0;
}

/*This function make the postfix logic*/
void to_postfix(char* src_buffer, char* dest_buffer, char* dest_operator)
{
  int i = 0;
  int j = 0;
  int last_index = 0;
  int op_i = 0;                              //i= source index and j=destination index
  char c;
  char last_op ;        //It's only working with the "last_index" as a CHAR, and it's very weird :/
  char operators[MAXSIZE];

  while ((c= src_buffer[i]) != '\0')
  {
    if (c=='+'|| c=='-'|| c=='*'|| c=='/')                //I'm chechik if its an operator or not
      {
        last_index = op_i-1;
        /* This "if" it's to make sure that I'm at the position 0 of my array "operator"*/
        if (last_index == -1)
          {
            operators[op_i] = c;
            printf("op[%d]=%c\n", op_i, c);
            print_user_input(operators);
            print_user_input(dest_buffer);
            op_i++;
          }
        else
          {
            last_op = operators[last_index];
            /** YOUR ERROR WAS THAT YOU CLOSED THE ELSE AND YOU PUT THE
            FOLLOWING CODE (IF-ELSE) OUTSIDE WHICH WAS WRONG.
            **/
            if (has_priority(c, last_op))
              {
                operators[op_i] = c;
                printf("op[%d]=%c\n", op_i, c);
                print_user_input(operators);
                print_user_input(dest_buffer);
                op_i++;
              }
            else
              {
                dest_buffer[j] = last_op;
                j++;
                operators[last_index] = c;
                printf("op[%d]=%c\n", last_index, c);
                print_user_input(operators);
                print_user_input(dest_buffer);
              }
            }
      }
    /*This "else if" check to see if it's a number, in this case anything diferent than a operator*/
    else if (c!='\n')
      {
        dest_buffer[j]=c;
        j++;
      }
    i++;
  }
  
  /*In this function I move the "+"" sign to the end o my destination buffer*/
  last_index = op_i - 1;
  if (last_index >= 0)
    {

      while (last_index >= 0)
        {
          dest_buffer[j] = operators[last_index];
          last_index--;
          j++;
        }
    }
  dest_buffer[i]='\0';
}

int main(void)
{
  printf("Calculator\n");

  char*buffer=(char*)malloc(25*sizeof(char));
  //char*src_buffer=(char*)malloc(25*sizeof(char));
  char*dest_buffer=(char*)malloc(25*sizeof(char));

  char*dest_operator=(char*)malloc(25*sizeof(char));

  //read_user_input(src_buffer);
  read_user_input(buffer);

  //print_user_input(src_buffer);
  print_user_input(buffer);

  //to_postfix(src_buffer, dest_buffer);
  to_postfix(buffer, dest_buffer, dest_operator);

  print_user_input(dest_buffer);

  //system("PAUSE");

  return 0;
}
