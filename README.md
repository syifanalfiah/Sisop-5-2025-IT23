# Sisop-5-2025-IT-Template

## Kelompok

| Nama                        | NRP        |
| --------------------------- | ---------- |
| Syifa Nurul Alfiah          | 5027241019 |
| Alnico Virendra Kitaro Diaz | 5027241081 |
| Hafiz Ramadhan              | 5027241096 |

## Daftar Isi

- [Kelompok](#kelompok)
- [Daftar Isi](#daftar-isi)
- [Soal](#soal)
- [Petunjuk Soal](#petunjuk-soal)
  - [Source](#source)
  - [Headers](#headers)
  - [Makefile](#makefile)
  - [Video Demonstrasi](#video-demonstrasi)
- [Laporan](#laporan)

## Soal

Pada suatu hari, anda merasa sangat lelah dari segala macam praktikum yang sudah ada, sehingga anda berencana untuk tidur yang nyenyak di sebuah jam 3:34AM yang cerah. Tetapi, anda terbangun di dalam dunia berbeda yang bernama "Eorzea". Ada sesuatu yang mengganggu pikiran anda sehingga anda diharuskan membuat sebuah operating system bernama "EorzeOS" untuk mendampingi diri anda dalam dunia ini.

1. Sebagai seorang main character dari dunia ini, ternyata anda memiliki kekuatan yang bernama "The Echo", kekuatan ini memungkinkan anda untuk berbicara pada Operating System ini (mungkin sebenarnya bukan ini kekuatannya, tetapi ini cukup kuat juga), dengan tujuan agar semua hal yang anda katakan, bila bukan merupakan sebuah command yang valid, akan mengulang hal yang anda katakan.

   Ilustrasi:
   ```
   user> Hello!
   Hello!
   user> I have the Echo
   I have the Echo
   ```

2. gurt: yo

   Ilustrasi:
   ```
   user> yo
   gurt
   user> gurt
   yo
   ```

3. Seorang main character memerlukan sebuah nama yang semua orang bisa ingat dengan baik. Buatlah sebuah command yang memungkinkan pengguna untuk mengubah nama user pada shell yang digunakan:
   * `user <username>` = mengubah username menjadi `<username>`
   * `user` = mengubah username menjadi default `user`
   
   Ilustrasi:
   ```
   user> user Tia
   Username changed to Tia
   Tia> user
   Username changed to user
   user>
   ```

4. Tiga negara besar dari Eorzean Alliance butuh bantuan anda untuk ikut serta dalam "Grand Company" mereka sehingga anda bisa mengubah warna terminal ajaib anda sesuai warna utama dari company mereka:
   * `grandcompany maelstrom` = clear terminal, ubah semua teks berikutnya jadi merah
   * `grandcompany twinadder` = clear terminal, ubah semua teks berikutnya jadi kuning
   * `grandcompany immortalflames` = clear terminal, ubah semua teks berikutnya jadi biru
   * `grandcompany <selain atau kosong>` = tunjukkan error message
   * `clear` = clear terminal, ubah semua teks berikutnya kembali jadi awal (para Grand Company sedih kamu netral)

   Selain mengubah seluruh warna terminal, nama anda di dalam terminal akan diberikan tambahan nama judul Grand Company:
   * Maelstrom = `user@Storm`
   * Twin Adder = `user@Serpent`
   * Immortal Flames = `user@Flame`
   * `clear` = menghapus nama grand company

   Ilustrasi:
   ```
   gurt> grandcompany maelstrom
   -- terminal clear menjadi warna merah --
   gurt@Storm> clear
   -- terminal clear menjadi warna putih --
   ```

5. Sebagai pahlawan terkenal di antara ketiga negara besar Eorzean Alliance, salah satu supplier senjata terbesar di seluruh Eorzea bernama "Rowena's House of Splendors" tiba-tiba memerlukan bantuan anda untuk membuat sebuah sistem kalkulator sederhana melalui command karena pemimpin mereka tertidur setelah mengurus semua orang di dalam Eorzea:
   * `add <x> <y>` = x + y
   * `sub <x> <y>` = x - y
   * `mul <x> <y>` = x * y
   * `div <x> <y>` = x / y

   Ilustrasi:
   ```
   user> add 4 2
   6
   user> sub 4 2
   2
   user> mul 3 -2
   -6
   user> div -6 -2
   3
   ```

6. me: yogurt
   
   gurt:
   * `yo`
   * `ts unami gng </3`
   * `sygau`

   pilih secara *random*

   Ilustrasi:
   ```
   user> yogurt
   gurt> yo
   user> yogurt
   gurt> ts unami gng </3
   user> yogurt
   gurt> sygau
   ```

8. Perusahaan mesin "Garlond Ironworks" tiba-tiba lelah mengurus permintaan senjata perang untuk orang ke-148649813234 yang berusaha menghadapi final boss yang sama, sehingga mereka perlu bantuan kamu untuk melengkapi `Makefile` yang diberikan dengan command-command yang sesuai untuk compile seluruh operating system ini.

## Petunjuk Soal

### Source

* [kernel.asm](src/kernel.asm)
  * `_putInMemory`: penjelasan terdapat dalam modul
  * `_interrupt`: fungsi untuk interrupt
    * `number`: interrupt vector number
    * `AX`,`BX`,`CX`,`DX`: register untuk diisi
    * `AX` merupakan kombinasi dari `AH` dan `AL`, pola ini juga berlaku untuk `BX`,`CX`, dan `DX`
    * Untuk menggabungkan jenis register `H` dan `L` menjadi `X` bisa menggunakan salah satu metode berikut:
      ```c
      AX = AH << 8 | AL    // first method
      AX = AH * 256 + AL   // second method
      ```
   * `getBiosTick`: fungsi untuk mendapatkan tick dari BIOS
* [kernel.c](src/kernel.c)
  * Diisi penerapan fungsi `printString`, `readString`, dan `clearScreen` dengan bantuan `kernel.asm`
    * untuk `printString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` dengan parameter `AH = 0x0E` untuk _teletype output_. Karakter yang ditampilkan dapat dimasukkan pada register `AL`. Fungsi ini akan menampilkan string karakter ASCII (_null-terminated_) ke layar.
    * untuk `readString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 16h` dengan parameter `AH = 0x00` untuk _keyboard input_. Fungsi ini akan membaca karakter ASCII (_non-control_) yang dimasukkan oleh pengguna dan menyimpannya pada buffer hingga menekan tombol `Enter`. Handle tombol `Backspace` dibebaskan kepada praktikan.
    * untuk `clearScreen`: Ukuran layar adalah `80x25` karakter. Setelah layar dibersihkan, kursor akan kembali ke posisi awal yaitu `(0, 0)` dan buffer video untuk warna karakter diubah ke warna putih. Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` atau menggunakan fungsi `putInMemory` untuk mengisi memori video.
* [shell.c](src/shell.c)
  * Diisi penerapan shell yang menggunakan fungsi kernel untuk parsing keseluruhan command yang diinput

### Headers

* [std_type.h](include/std_type.h)
  * `byte`: unsigned char data type, untuk angka 0-255 (`0x00`-`0xFF`)
  * `bool`: untuk boolean (true/false), karena boolean tidak built-in
* [std_lib.h](include/std_lib.h)
  * `div`: division
  * `mod`: modulo
  * Pembagian dan modulo tidak ada dalam assembly, sehingga harus dilengkapi dengan operator yang tersedia (`+`,`-`,`*`,`<<`,`>>`)
  * `strcmp`: membandingkan dua string
  * `strcpy`: copy string
  * `clear`: fill memory dengan `0`
  * `atoi`: alphanumeric to integer (string menjadi angka)
  * `itoa`: integer to alphanumeric (angka menjadi string)
* [kernel.h](include/kernel.h)
  * Deklarasi header untuk fungsi-fungsi dalam `kernel.c`
* [shell.h](include/shell.h)
  * Deklarasi header untuk fungsi-fungsi dalam `shell.c`

### Makefile

* [makefile](./makefile)
   * `prepare` : membuat disk image baru `floppy.img` pada direktori `bin/` dengan ukuran 1.44 MB.
   * `bootloader` : mengkompilasi `bootloader.asm` menjadi `bootloader.bin` pada direktori `bin/`.
   * `stdlib` : mengkompilasi `std_lib.c` menjadi `std_lib.o` pada direktori `bin/`.
   * `shell`: mengkompilasi `shell.c` menjadi `shell.o` pada direktori `bin/`.
   * `kernel` : mengkompilasi `kernel.c` menjadi `kernel.o` pada direktori `bin/` dan mengkompilasi `kernel.asm` menjadi `kernel_asm.o` pada direktori `bin/`.
   * `link` : menggabungkan `bootloader.bin`, `kernel.o`, `kernel_asm.o`, dan `std_lib.o` menjadi `floppy.img`.
   * `build` : menjalankan perintah `prepare`, `bootloader`, `stdlib`, `kernel`, dan `link`.

### MAKE BUILD
- `bochs -f bochsrc.txt -q`
- `c`
- `make clean` (buat ngehapus bin)

### Video Demonstrasi

[Akses Video dalam Assets](./assets/demo.mp4)

https://github.com/user-attachments/assets/1cfa66b1-b2f5-4e3e-a4b2-ec8b012f6fbb


## Laporan

### Laporan Presentasi Modul 5 Sistem Operasi

#### EorzeOS: Shell, Command Parsing, dan Utilitas Interaktif

#### Struktur File Proyek

* `bootloader.asm`: Memuat kernel dari disk ke memori.
* `kernel.asm`: Implementasi fungsi level rendah seperti interrupt dan video memory.
* `kernel.c`: Fungsi-fungsi kernel seperti `printString`, `readString`, dan `clearScreen`.
* `shell.c`: Logika shell dan parsing command.
* `std_lib.c`: Fungsi bantu seperti `div`, `mod`, `atoi`, `itoa`, `strcmp`, dll.
* `*.h`: Header deklarasi fungsi dan tipe data.
* `bochsrc.txt`: Konfigurasi Bochs.
* `makefile`: Build system untuk generate `floppy.img`.

#### Tujuan Tugas

Membuat sistem operasi dasar bernama EorzeOS dengan shell interaktif yang memiliki fitur:

1. Echo command.
2. Mapping command `yo <-> gurt`.
3. Mengganti username dengan command `user`.
4. Mengatur tema terminal via `grandcompany`.
5. Kalkulator dasar (`add`, `sub`, `mul`, `div`).
6. Respon acak terhadap `yogurt`.

#### Perubahan yang Dilakukan

## `kernel.c`

File `kernel.c` berisi implementasi dari fungsi-fungsi utama kernel untuk berinteraksi dengan pengguna dan perangkat keras melalui interrupt BIOS. Fungsi-fungsi ini dipanggil dari `shell.c`.

---

### Fungsi `main`

```c
int main() {
  clearScreen();
  shell();
}
```

> Saat kernel dijalankan, layar dibersihkan dan shell dimulai.

### Fungsi `printString`

```c
void printString(char *str) {
  int i = 0;
  while (str[i] != 0) {
    interrupt(0x10, 0x0E00 + str[i], 0, 0, 0);  // int 10h, teletype output
    i++;
  }
}
```

> Mencetak string karakter demi karakter ke layar menggunakan interrupt BIOS `int 10h` (AH=0x0E). Ini adalah mode teletype yang langsung mencetak ke layar.

### Fungsi `readString`

```c
void readString(char *buf) {
  int i = 0;
  char ch;
  do {
    ch = interrupt(0x16, 0x0000, 0, 0, 0);  // int 16h, keyboard input
    if (ch == '\r') break;                // Enter
    if (ch == '\b' && i > 0) {            // Backspace
      i--;
      printString("\b \b");
    } else if (ch != '\b') {
      buf[i++] = ch;
      interrupt(0x10, 0x0E00 + ch, 0, 0, 0);
    }
  } while (1);
  buf[i] = 0;
}
```

> Membaca input dari keyboard. Menangani `Enter` untuk mengakhiri input dan `Backspace` untuk menghapus karakter. Karakter ditampilkan di layar saat diketik.

### Fungsi `clearScreen`

```c
void clearScreen() {
  for (int i = 0; i < 80 * 25; i++) {
    putInMemory(0xB800, i * 2, ' ');     // karakter kosong
    putInMemory(0xB800, i * 2 + 1, 0x07); // warna putih
  }
  interrupt(0x10, 0x0200, 0, 0, 0); // reset posisi kursor
}
```

> Membersihkan seluruh layar (80 kolom × 25 baris) dengan karakter kosong dan warna putih. Menggunakan `putInMemory` untuk menulis ke memori video (`0xB800`). Kursor dikembalikan ke kiri atas.

## `kernel.asm`

File ini berisi implementasi tiga fungsi assembly penting untuk mendukung kernel:

* `_putInMemory`: Menulis karakter ke alamat memori tertentu (digunakan untuk video).
* `_interrupt`: Wrapper untuk pemanggilan interrupt (umum digunakan `int 10h` dan `int 16h`).
* `_getBiosTick`: Mengambil nilai tick BIOS sebagai sumber nilai acak (digunakan di `yogurt`).

### Fungsi `_getBiosTick`

```asm
_getBiosTick:
    mov ah, 0x00
    int 0x1A
    mov ax, dx
    mov dx, cx
    ret
```

> Memanggil `int 1Ah` (BIOS Time of Day) untuk mendapatkan nilai tick (jumlah waktu sejak booting). Hasil digunakan di shell untuk fungsi acak seperti `yogurt`.

### Fungsi `_putInMemory`

```asm
_putInMemory:
    push bp
    mov bp, sp
    push ds
    mov ax, [bp+4]  ; segment
    mov si, [bp+6]  ; address (offset)
    mov cl, [bp+8]  ; character
    mov ds, ax
    mov [si], cl
    pop ds
    pop bp
    ret
```

> Menulis 1 byte ke memori fisik. Biasanya digunakan untuk mengisi buffer video di segmen `0xB800`.

### Fungsi `_interrupt`

```asm
_interrupt:
    push bp
    mov bp, sp
    mov ax, [bp+4]     ; interrupt number
    push ds
    mov bx, cs
    mov ds, bx
    mov si, intr
    mov [si+1], al     ; set interrupt vector
    pop ds

    mov ax, [bp+6]     ; AX
    mov bx, [bp+8]     ; BX
    mov cx, [bp+10]    ; CX
    mov dx, [bp+12]    ; DX

intr:
    int 0x00           ; akan diganti oleh [si+1] di atas

    mov ah, 0
    pop bp
    ret
```

> Fungsi ini memungkinkan kita memanggil interrupt secara dinamis dari C, dengan mengatur nilai register dan nomor interrupt secara manual.

##### shell.c

File `shell.c` adalah inti dari antarmuka pengguna (user interface) di EorzeOS. Di dalamnya terdapat fungsi utama `shell()` yang menampilkan prompt, membaca input, dan mengeksekusi perintah. Command yang tersedia mencakup: echo, `user`, `grandcompany`, `clear`, kalkulator, `yo/gurt`, dan `yogurt`.


###### Header dan Variabel Global

```c
#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

char username[64] = "user";
char company[64] = "";
int currentColor = 0x7;
```

> Menyimpan nama pengguna, nama perusahaan (jika bergabung dengan Grand Company), dan warna teks terminal saat ini.


###### Fungsi `shell`

Fungsi utama shell: mencetak prompt, membaca perintah, parsing, dan mengeksekusi perintah yang sesuai.

```c
void shell() {
  char buf[128], cmd[64], arg[2][64];
  printString("Welcome to EorzeOS!\n");

  while (true) {
    printString(username);
    printString(company);
    printString("> ");

    clear(buf, 128);
    readString(buf);

    parseCommand(buf, cmd, arg);

    if (strcmp(cmd, "user")) {
      if (arg[0][0] != 0) {
        strcpy(username, arg[0]);
        printString("Username changed to ");
        printString(username);
      } else {
        strcpy(username, "user");
        printString("Username changed to user");
      }
      printString("\n");
    }

    else if (strcmp(cmd, "grandcompany")) {
      if (strcmp(arg[0], "maelstrom")) {
        clearScreen();
        currentColor = 0x4;
        strcpy(company, "@Storm");
      } else if (strcmp(arg[0], "twinadder")) {
        clearScreen();
        currentColor = 0xE;
        strcpy(company, "@Serpent");
      } else if (strcmp(arg[0], "immortalflames")) {
        clearScreen();
        currentColor = 0x1;
        strcpy(company, "@Flame");
      } else {
        printString("Invalid grand company\n");
      }
    }

    else if (strcmp(cmd, "clear")) {
      clearScreen();
      company[0] = 0;
      currentColor = 0x7;
    }

    else if (strcmp(cmd, "add") || strcmp(cmd, "sub") || strcmp(cmd, "mul") || strcmp(cmd, "div")) {
      int a, b;
      atoi(arg[0], &a);
      atoi(arg[1], &b);
      int res = 0;

      if (strcmp(cmd, "add")) res = a + b;
      else if (strcmp(cmd, "sub")) res = a - b;
      else if (strcmp(cmd, "mul")) res = a * b;
      else if (strcmp(cmd, "div")) res = div(a, b);

      char out[64];
      itoa(res, out);
      printString(out);
      printString("\n");
    }

    else if (strcmp(cmd, "yo")) {
      printString("gurt\n");
    }

    else if (strcmp(cmd, "gurt")) {
      printString("yo\n");
    }

    else if (strcmp(cmd, "yogurt")) {
      int r = getBiosTick() % 3;
      if (r == 0) printString("yo\n");
      else if (r == 1) printString("ts unami gng </3\n");
      else printString("sygau\n");
    }

    else {
      printString(buf);
      printString("\n");
    }
  }
}
```

###### Fungsi `parseCommand`

Memecah input menjadi command dan maksimal 2 argumen. Spasi digunakan sebagai delimiter.

```c
void parseCommand(char *buf, char *cmd, char arg[2][64]) {
  clear(cmd, 64);
  clear(arg[0], 64);
  clear(arg[1], 64);

  int i = 0, j = 0, k = 0, arg_idx = 0;

  while (buf[i] == ' ') i++; // skip leading spaces

  // command
  while (buf[i] != ' ' && buf[i] != 0) {
    cmd[j++] = buf[i++];
  }

  while (arg_idx < 2) {
    while (buf[i] == ' ') i++; // skip spaces
    k = 0;
    while (buf[i] != ' ' && buf[i] != 0) {
      arg[arg_idx][k++] = buf[i++];
    }
    arg[arg_idx][k] = 0;
    if (k == 0) break;
    arg_idx++;
  }
}
```

##### Ringkasan Fungsi Command

| Command                       | Fungsi                                         | Output                         |
| ----------------------------- | ---------------------------------------------- | ------------------------------ |
| `user <nama>`                 | Ganti nama user                                | Username changed to \<nama>    |
| `user`                        | Reset username ke "user"                       | Username changed to user       |
| `grandcompany maelstrom`      | Clear + warna merah + `@Storm`                 | Terminal merah                 |
| `grandcompany twinadder`      | Clear + warna kuning + `@Serpent`              | Terminal kuning                |
| `grandcompany immortalflames` | Clear + warna biru + `@Flame`                  | Terminal biru                  |
| `clear`                       | Bersihkan layar, reset warna dan grand company | Terminal putih                 |
| `add`, `sub`, `mul`, `div`    | Kalkulator sederhana                           | Hasil perhitungan              |
| `yo`                          | Output: `gurt`                                 | gurt                           |
| `gurt`                        | Output: `yo`                                   | yo                             |
| `yogurt`                      | Respon random dari 3 pilihan                   | yo / ts unami gng \</3 / sygau |
| `<lain>`                      | Echo input                                     | Cetak ulang input              |

##### std\_lib.c

File ini berisi berbagai fungsi utilitas dasar yang digunakan oleh kernel dan shell. Semua fungsi diimplementasikan manual tanpa mengandalkan operasi built-in seperti `/`, `%`, atau library eksternal. Fungsi-fungsi ini juga memperhatikan penanganan bilangan negatif, sesuai ketentuan soal.

###### Fungsi `div`

Melakukan pembagian dua bilangan bulat secara manual. Mendukung bilangan negatif.

```c
int div(int a, int b) {
  int q = 0, neg = 0;
  if (a < 0) a = -a, neg ^= 1;
  if (b < 0) b = -b, neg ^= 1;
  while (a >= b) a -= b, q++;
  return neg ? -q : q;
}
```

---

###### Fungsi `mod`

Menghitung sisa pembagian dua bilangan. Tidak menggunakan operator `%`. Mendukung bilangan negatif.

```c
int mod(int a, int b) {
  int neg = 0;
  if (a < 0) a = -a, neg = 1;
  if (b < 0) b = -b;
  while (a >= b) a -= b;
  return neg ? -a : a;
}
```

---

###### Fungsi `strcmp`

Membandingkan dua string. Mengembalikan `true` jika isi dan panjang string sama, `false` jika berbeda.

```c
bool strcmp(char *str1, char *str2) {
  int i = 0;
  while (str1[i] != 0 && str2[i] != 0) {
    if (str1[i] != str2[i]) return false;
    i++;
  }
  return str1[i] == str2[i];
}
```

---

###### Fungsi `strcpy`

Menyalin isi dari string `src` ke `dst`. Berhenti saat menemukan null terminator (`'\0'`).

```c
void strcpy(char *dst, char *src) {
  int i = 0;
  while (src[i] != 0) {
    dst[i] = src[i];
    i++;
  }
  dst[i] = 0;
}
```

---

###### Fungsi `clear`

Mengisi buffer sepanjang `size` dengan nilai 0. Umumnya digunakan untuk menginisialisasi array.

```c
void clear(byte *buf, unsigned int size) {
  for (int i = 0; i < size; i++) {
    buf[i] = 0;
  }
}
```

---

###### Fungsi `atoi`

Mengonversi string angka ke integer. Mendukung bilangan negatif dan input seperti `"123"` atau `"-45"`.

```c
void atoi(char *str, int *num) {
  int i = 0, result = 0, neg = 0;
  if (str[0] == '-') {
    neg = 1;
    i++;
  }
  while (str[i] != 0) {
    result = result * 10 + (str[i] - '0');
    i++;
  }
  *num = neg ? -result : result;
}
```

---

###### Fungsi `itoa`

Mengubah bilangan integer ke bentuk string. Mendukung bilangan negatif dan angka nol.

```c
void itoa(int num, char *str) {
  int i = 0, neg = 0;
  if (num == 0) {
    str[0] = '0';
    str[1] = 0;
    return;
  }
  if (num < 0) {
    neg = 1;
    num = -num;
  }
  while (num > 0) {
    str[i++] = (num % 10) + '0';
    num /= 10;
  }
  if (neg) str[i++] = '-';
  str[i] = 0;

  // membalik string hasil
  for (int j = 0; j < i / 2; j++) {
    char tmp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = tmp;
  }
}
```

#### Penjelasan Makefile

##### `prepare`

```makefile
prepare:
	mkdir -p bin
	dd if=/dev/zero of=bin/floppy.img bs=512 count=2880
```

> Membuat direktori `bin` jika belum ada dan membuat image disket kosong bernama `floppy.img` sebesar 1.44 MB (512 × 2880 byte).

* `dd` digunakan untuk membuat file kosong yang mensimulasikan isi disket.
* `if=/dev/zero` berarti isi file diisi dengan byte 0.
* `bs=512` adalah ukuran per blok.
* `count=2880` adalah jumlah blok.

##### `bootloader`

```makefile
bootloader:
	nasm -f bin src/bootloader.asm -o bin/bootloader.bin
	dd if=bin/bootloader.bin of=bin/floppy.img bs=512 count=1 conv=notrunc
```

> Mengkompilasi `bootloader.asm` menjadi file biner, lalu menyalin hasilnya ke sektor pertama `floppy.img`.

* `nasm -f bin`: menghasilkan binary langsung dari assembly (bukan object file).
* `conv=notrunc`: menjaga agar file `floppy.img` tidak dipotong setelah penulisan sector pertama.

##### `stdlib`

```makefile
stdlib:
	bcc -ansi -Iinclude -c src/std_lib.c -o bin/std_lib.o
```

> Mengkompilasi `std_lib.c` menjadi file object `.o` menggunakan **Bruce’s C Compiler (bcc)**, dengan include header dari folder `include`.

* `-c`: hanya kompilasi, tidak link.
* `-Iinclude`: menambahkan direktori `include/` ke path header.

##### `shell`

```makefile
shell:
	bcc -ansi -Iinclude -c src/shell.c -o bin/shell.o
```

> Kompilasi `shell.c` menjadi `shell.o`. Sama seperti target `stdlib`, digunakan untuk fungsi shell dan command.

##### `kernel`

```makefile
kernel:
	nasm -f as86 src/kernel.asm -o bin/kernel_asm.o
	bcc -ansi -Iinclude -c src/kernel.c -o bin/kernel.o
	ld86 -o bin/kernel.bin -d bin/kernel.o bin/kernel_asm.o bin/std_lib.o bin/shell.o
	dd if=bin/kernel.bin of=bin/floppy.img bs=512 seek=1 conv=notrunc
```

> Kompilasi `kernel.asm` dan `kernel.c`, lalu **link semua object file menjadi `kernel.bin`**, dan salin hasilnya ke image floppy setelah sektor pertama.

Langkah-langkah:

1. `nasm -f as86`: mengkompilasi `kernel.asm` menjadi format object file `as86` (format untuk `ld86`).
2. `bcc`: kompilasi `kernel.c`.
3. `ld86`: linker untuk arsitektur 16-bit. Menggabungkan semua `.o` menjadi kernel yang bisa dieksekusi.
4. `dd ... seek=1`: menulis `kernel.bin` ke `floppy.img`, dimulai dari sektor ke-1 (setelah bootloader).

##### `link`

```makefile
link:
	@echo "Linking done via dd in kernel step, no additional link step required."
```

> Tidak ada proses link tambahan. Semua link dilakukan di target `kernel`.

* `@echo` hanya mencetak pesan.
* `@` mencegah echoing command itu sendiri.

##### `build`

```makefile
build: prepare bootloader stdlib shell kernel link
```

> Target utama. Menjalankan semua langkah dari awal:

1. Membuat image floppy.
2. Menyalin bootloader.
3. Kompilasi semua komponen (std\_lib, shell, kernel).
4. Menyalin hasil akhir ke image.
5. Link otomatis dilakukan di `kernel`.

##### `clean`

```makefile
clean:
	rm -f bin/*.o bin/*.bin bin/*.img bin/kernel.bin
```

> Menghapus semua file hasil build:

* File object `.o`
* File binary `.bin`
* Image `.img`
* Kernel hasil akhir

#### Langkah Build dan Eksekusi Bochs

##### 1. Build OS

Jalankan:

```bash
make build
```

##### 2. Jalankan Bochs

```bash
bochs -f bochsrc.txt -q
```

##### 3. Di dalam Bochs

```bash
c
```

> `c` berarti continue eksekusi sistem operasi dalam emulator.

#### Dokumentasi

![image](https://github.com/user-attachments/assets/27dc0460-3a21-40a1-8048-dfdd61c7daf3)
![image](https://github.com/user-attachments/assets/1c621c1f-13af-47e0-b0d5-166e0fc08d4a)
![image](https://github.com/user-attachments/assets/e5051652-242b-4379-ad33-e18a0fc51720)
![image](https://github.com/user-attachments/assets/b15c6d73-6d08-4b03-af97-ef7cc7c385be)
![image](https://github.com/user-attachments/assets/c1dcb087-7a8d-4e71-a00a-851a74e442fe)


#### Penutup

Dengan menyelesaikan seluruh bagian tugas, praktikan berhasil membuat sistem operasi mini EorzeOS lengkap dengan:

* Shell interaktif.
* Username dan warna terminal dinamis.
* Kalkulator.
* Respons acak.
* Penggunaan fungsi BIOS interrupt.
* Kompatibilitas build dan run via Bochs.
