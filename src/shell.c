#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

char grandcompany[16];
int current_color;

void shell() {
  char buf[128];
  char cmd[64];
  char arg[2][64];
  char username[32];
  char result_str[32];
  int num1, num2, result;
  unsigned int tick;
  int choice;

  strcpy(username, "user");
  strcpy(grandcompany, "");
  current_color = 0x07;

  printString("Welcome to EorzeOS!\r\n");

  while (true) {
    clear((byte*)buf, 128);
    clear((byte*)cmd, 64);
    clear((byte*)arg[0], 64);
    clear((byte*)arg[1], 64);

    printString(username);
    if (strcmp(grandcompany, "maelstrom") == 1) {
      printString("@Storm");
    } else if (strcmp(grandcompany, "twinadder") == 1) {
      printString("@Serpent");
    } else if (strcmp(grandcompany, "immortalflames") == 1) {
      printString("@Flame");
    }
    printString("> ");

    readString(buf);

    parseCommand(buf, cmd, arg);

    if (strcmp(cmd, "yo") == 1) {
      printString("gurt\r\n");
    }
    else if (strcmp(cmd, "gurt") == 1) {
      printString("yo\r\n");
    }
    else if (strcmp(cmd, "user") == 1) {
      if (arg[0][0] == '\0') {
        strcpy(username, "user");
        printString("Username changed to user\r\n");
      } else {
        strcpy(username, arg[0]);
        printString("Username changed to ");
        printString(username);
        printString("\r\n");
      }
    }
    else if (strcmp(cmd, "grandcompany") == 1) {
      if (strcmp(arg[0], "maelstrom") == 1) {
        strcpy(grandcompany, "maelstrom");
        clearScreen();
        current_color = 0x0C;
        setTextColor(current_color);
      }
      else if (strcmp(arg[0], "twinadder") == 1) {
        strcpy(grandcompany, "twinadder");
        clearScreen();
        current_color = 0x0E;
        setTextColor(current_color);
      }
      else if (strcmp(arg[0], "immortalflames") == 1) {
        strcpy(grandcompany, "immortalflames");
        clearScreen();
        current_color = 0x09;
        setTextColor(current_color);
      }
      else {
        printString("Error: Invalid grand company\r\n");
      }
    }
    else if (strcmp(cmd, "clear") == 1) {
      strcpy(grandcompany, "");
      clearScreen();
      current_color = 0x07;
      setTextColor(current_color);
    }
    else if (strcmp(cmd, "add") == 1) {
      atoi(arg[0], &num1);
      atoi(arg[1], &num2);
      result = num1 + num2;
      itoa(result, result_str);
      printString(result_str);
      printString("\r\n");
    }
    else if (strcmp(cmd, "sub") == 1) {
      atoi(arg[0], &num1);
      atoi(arg[1], &num2);
      result = num1 - num2;
      itoa(result, result_str);
      printString(result_str);
      printString("\r\n");
    }
    else if (strcmp(cmd, "mul") == 1) {
      atoi(arg[0], &num1);
      atoi(arg[1], &num2);
      result = num1 * num2;
      itoa(result, result_str);
      printString(result_str);
      printString("\r\n");
    }
    else if (strcmp(cmd, "div") == 1) {
      atoi(arg[0], &num1);
      atoi(arg[1], &num2);
      if (num2 != 0) {
        result = div(num1, num2);
        itoa(result, result_str);
        printString(result_str);
        printString("\r\n");
      } else {
        printString("Error: Division by zero\r\n");
      }
    }
    else if (strcmp(cmd, "yogurt") == 1) {
      tick = getBiosTick();
      choice = mod(tick, 3);
      
      if (choice == 0) {
        printString("yo\r\n");
      } else if (choice == 1) {
        printString("sygau\r\n");
      } else {
        printString("ts unami gng </3\r\n");
      }
    }
    else {
      printString(buf);
      printString("\r\n");
    }
  }
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
  int i = 0, j = 0;
  int state = 0;
  
  cmd[0] = '\0';
  arg[0][0] = '\0';
  arg[1][0] = '\0';
  
  while (buf[i] != '\0') {
    if (buf[i] == ' ') {
      while (buf[i] == ' ') i++;
      
      if (state == 0) {
        cmd[j] = '\0';
        state = 1;
        j = 0;
      } else if (state == 1) {
        arg[0][j] = '\0';
        state = 2;
        j = 0;
      }
      continue;
    }
    
    if (state == 0) {
      cmd[j++] = buf[i];
    } else if (state == 1) {
      arg[0][j++] = buf[i];
    } else if (state == 2) {
      arg[1][j++] = buf[i];
    }
    
    i++;
  }
  
  if (state == 0) {
    cmd[j] = '\0';
  } else if (state == 1) {
    arg[0][j] = '\0';
  } else if (state == 2) {
    arg[1][j] = '\0';
  }
}
