#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

pid_t parent, child;

void handler(int signum){}

int main() {  
  signal(SIGINT,handler);
  parent = getpid();
  child = fork ();
  if (child == 0) {
      for (int i = 0; i < 500; i++) {
        printf ("Child: %d\n", i); //Child prints
        kill(parent,SIGINT); //Sends a signal to parent
        pause(); //Waits for parent's signal
      }
      printf ("Child ends\n");
    }
  else
    { 
      for (int j = 0; j < 500; j++) {
          printf ("Parent: %d\n", j);
          kill(child,SIGINT); //Sends a signal to child
          pause(); //waits
      }
    }
}