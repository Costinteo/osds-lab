#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>



bool riddle() {
   const char* riddle = "In the dark I sing, though I’m not heard by all, I warn of a danger, a silent deadly call. In coal mines I dwell, where miners are near, if I fall, their lives could disappear.";

   char input[30];
   char temp;

   int index = 0;
   int read_nr_b;


   printf("How many bytes do you want to write?\n");
   scanf("%d",&read_nr_b);
   getchar(); // Consume newline

   printf("%s. What am I?\n", riddle);
   while(read_nr_b > 0){
    input[index++] = getchar();    
    read_nr_b--;
   }
  
   if(strcmp(input, "canary") == 0) return true;
   return false;

}

void win() {
  char prize[1];
  printf("Use your reward for being the best riddle solver!");
  gets(prize);

}


int main(int argc, char *argv[]) {
  pid_t p;
  bool solved = false;
  int (*reward)(const char *) = system;

  while( solved == false){

      if( (p = fork()) == 0){
            solved = riddle();
          exit(solved ? 0 : 1);
      } else if (p<0){
          perror("Fork failed");
          exit(1);
      } else {
              int status;
          wait(&status);
          if(WIFEXITED(status) && WEXITSTATUS(status) == 0){
          solved = true;
          }
      }
  }


  printf("Correct. Your reward is: %p", reward);
  fflush(stdout);

  win();
  return 0;
}
