#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void main() {
  pid_t Padre_pid, Hijo_pid;

  
  int N;
  printf("Escribe la variable:");
  scanf("%d", &N);

  Hijo_pid = fork();

  if (Hijo_pid == -1 ) //Ha ocurrido un error 
  {
    printf("No se ha podido crear el proceso hijo...");
    exit(-1);       
  }
  if (Hijo_pid == 0 )  //Nos encontramos en Proceso hijo 
  {        
    printf("Soy el proceso hijo \n\t Mi PID es %d, El PID de mi padre es: %d.\n",  
            getpid(), getppid() );
            N+=5;
  }
  else    //Nos encontramos en Proceso padre 
  { 
   Hijo_pid = wait(NULL); //espera la finalización del proceso hijo
   printf("Soy el proceso padre:\n\t Mi PID es %d, El PID de mi padre es: %d.\n\t Mi hijo: %d terminó.\n",  getpid(), getppid(), Padre_pid);  
   N-=4;
   }

 printf("La variable vale ahora: %d\n", N);
  
  exit(0);
}
