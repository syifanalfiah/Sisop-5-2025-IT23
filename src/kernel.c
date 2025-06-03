#include "shell.h"
#include "kernel.h"

int current_color;

int main() {
  current_color = 0x07; 
  clearScreen();
  shell();
  return 0;
}

void printString(char *str) {
  while (*str != '\0') {
    interrupt(0x10, 0x0E00 + *str, 0, 0, 0);
    str++;
  }
}

void readString(char *buf) {
  int i = 0;
  char c;

  while (1) {
    c = interrupt(0x16, 0, 0, 0, 0);

    if (c == 0x0D) { 
      buf[i] = '\0';
      printString("\r\n");
      break;
    }
    else if (c == 0x08 && i > 0) { 
      i--;
      printString("\b \b");
    }
    else if (c >= 32 && c <= 126 && i < 255) { 
      buf[i++] = c;
      interrupt(0x10, 0x0E00 + c, 0, 0, 0);
    }
  }
}

void clearScreen() {
  int i;  
  interrupt(0x10, 0x0200, 0, 0, 0);

  for (i = 0; i < 80 * 25; i++) {
    putInMemory(0xB000, 0x8000 + i * 2, ' ');
    putInMemory(0xB000, 0x8001 + i * 2, current_color);
  }
}

void setTextColor(int color) {
  int i;           
  current_color = color; 

  for (i = 0; i < 80 * 25; i++) {
    putInMemory(0xB000, 0x8001 + i * 2, color);
  }
}

