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

## 1. The Echo
Shell dapat mengenali input yang tidak dikenali sebagai perintah dan akan mencetak kembali input tersebut, merepresentasikan kemampuan "The Echo" dari karakter utama.


### 🔍 Penjelasan Fungsi Fitur:
Shell akan:

Menerima input dari user.

Mengecek apakah input tersebut termasuk perintah yang dikenali, seperti:

`change-username`

`change-theme`

`calc`

`exit`, dsb.

Jika tidak termasuk perintah-perintah tersebut, maka:

Shell akan mencetak kembali (echo) teks input tersebut ke layar.

### 🔧 Implementasi 
```C
while (true) {
    printf("%s> ", username);        // Menampilkan prompt

    fgets(input, sizeof(input), stdin); // Menerima input

    if (strcmp(input, "exit\n") == 0) {
        break;
    } else if (strcmp(input, "change-username\n") == 0) {
        // Jalankan fungsi ganti username
    } else if (strcmp(input, "change-theme\n") == 0) {
        // Jalankan fungsi ganti tema
    } else if (strcmp(input, "calc\n") == 0) {
        // Jalankan kalkulator
    } else {
        // Bagian ini adalah fitur "The Echo"
        printf("%s", input);   // Cetak ulang input
    }
}

```
Contoh:
```
user> Hello!
Hello!
```

## 2. Fitur gurt
Implementasi sistem `gurt` yang akan mengeluarkan `yo` saat pengguna mengetik `gurt`, dan sebaliknya. Ditambahkan juga perintah `yogurt` yang akan menampilkan salah satu dari tiga kemungkinan output secara acak:
- `yo`
- `ts unami gng </3`
- `sygau`

### 📌 Penjelasan Fitur "gurt"
Tujuan:
Jika user mengetik `gurt`, maka output-nya adalah `yo`.

Jika user mengetik `yo`, maka output-nya adalah `gurt`.

Jika user mengetik `yogurt`, maka akan ditampilkan salah satu dari 3 output secara acak:

1. `yo`

2. `ts unami gng </3`

3. `sygau`

### 🔧 Implementasi

```C
if (input == "yo") {
    print("gurt");
}
else if (input == "gurt") {
    print("yo");
}
else if (input == "yogurt") {
    // generate random number between 0 and 2
    switch(rand() % 3) {
        case 0: print("yo"); break;
        case 1: print("ts unami gng </3"); break;
        case 2: print("sygau"); break;
    }
}

```

Contoh:
```
user> yogurt
gurt> ts unami gng </3
```

## 3. Ganti Username
Command `user <nama>` mengubah username shell sesuai input, sedangkan `user` mengembalikannya ke default `user`.

### 📌 Perintah:
user <nama> → Mengubah nama prompt menjadi <nama>.

user → Mengembalikan nama prompt ke default, yaitu user.

## 💡 Implementasi

```c
prompt = "user"

while True:
    input_cmd = input(f"{prompt}> ")
    tokens = input_cmd.split()

    if tokens[0] == "user":
        if len(tokens) == 2:
            prompt = tokens[1]
            print(f"Username changed to {prompt}")
        else:
            prompt = "user"
            print("Username changed to user")

```

Contoh:
```
user> user Tia
Username changed to Tia
Tia> user
Username changed to user
```


### 4. Grand Company
Shell mendukung command untuk bergabung ke Grand Company, mengubah warna terminal dan nama prompt:
- `grandcompany maelstrom` → merah, `@Storm`
- `grandcompany twinadder` → kuning, `@Serpent`
- `grandcompany immortalflames` → biru, `@Flame`
- `clear` → netral (putih), hapus afiliasi Grand Company

### 🎯 Tujuan Fitur

Fitur ini memungkinkan pengguna shell untuk:

1. Bergabung dengan salah satu dari 3 Grand Company.

2. Shell akan menyesuaikan:

  - Warna terminal.

  - Nama prompt (menambahkan tag sesuai afiliasi).

3. Perintah `clear` digunakan untuk:

  - Menghapus afiliasi.

  - Mengembalikan warna dan prompt ke kondisi default.

## 🧩 Mapping Perintah dan Efeknya

| Perintah                             | Warna Terminal     | Format Prompt       |
|-------------------------------------|--------------------|---------------------|
| `grandcompany maelstrom`            | Merah              | `<nama>@Storm`      |
| `grandcompany twinadder`            | Kuning             | `<nama>@Serpent`    |
| `grandcompany immortalflames`       | Biru               | `<nama>@Flame`      |
| `clear`                             | Putih (netral)     | `<nama>`            |


### 🧠 Implementasi

```c
prompt_name = "user"
affiliation = None  # None, or 'Storm', 'Serpent', 'Flame'
color = "white"

input_cmd = input(f"{prompt_name}@{affiliation if affiliation else ''}> ")

if input_cmd.startswith("grandcompany"):
    _, gc = input_cmd.split()
    if gc == "maelstrom":
        affiliation = "Storm"
        color = "red"
    elif gc == "twinadder":
        affiliation = "Serpent"
        color = "yellow"
    elif gc == "immortalflames":
        affiliation = "Flame"
        color = "blue"

elif input_cmd == "clear":
    affiliation = None
    color = "white"

```
Contoh:
```
user> grandcompany maelstrom
gurt@Storm> clear
user>
```

### 5. Kalkulator
Shell mendukung 4 operasi matematika dasar dengan command:
- `add <x> <y>`
- `sub <x> <y>`
- `mul <x> <y>`
- `div <x> <y>`

### 🎯 Tujuan Fitur
Memberikan kemampuan bagi user untuk melakukan empat operasi matematika dasar langsung dari terminal shell, dengan sintaks sederhana.

## 📊 Daftar Operasi

| Command         | Fungsi                        | Contoh       | Output |
|-----------------|-------------------------------|--------------|--------|
| `add <x> <y>`   | Penjumlahan                   | `add 3 2`    | `5`    |
| `sub <x> <y>`   | Pengurangan                   | `sub 5 8`    | `-3`   |
| `mul <x> <y>`   | Perkalian                     | `mul 3 -2`   | `-6`   |
| `div <x> <y>`   | Pembagian bilangan bulat      | `div 10 2`   | `5`    |

### 🧠 Konsep

```c
cmd = input("> ")
tokens = cmd.split()  # Misalnya: ['mul', '3', '-2']

if tokens[0] == "add":
    print(int(tokens[1]) + int(tokens[2]))
elif tokens[0] == "sub":
    print(int(tokens[1]) - int(tokens[2]))
elif tokens[0] == "mul":
    print(int(tokens[1]) * int(tokens[2]))
elif tokens[0] == "div":
    if int(tokens[2]) != 0:
        print(int(tokens[1]) // int(tokens[2]))
    else:
        print("Error: Division by zero")

```

Contoh:
```
user> mul 3 -2
-6
```

### 6. Makefile
File `makefile` sudah lengkap dan dapat menjalankan semua tahapan:
- `prepare` untuk membuat floppy image
- `bootloader` meng-assemble bootloader
- `stdlib`, `shell`, `kernel` untuk meng-compile masing-masing bagian
- `link` untuk menggabungkan semuanya
- `build` sebagai shortcut untuk semua langkah di atas

🎯 Tujuan Makefile
Makefile ini digunakan untuk meng-otomatisasi proses build dari sistem, sehingga Anda cukup menjalankan satu perintah seperti:

`make build`

## ⚙️ Tahapan Build

Makefile ini memiliki beberapa target:

| Target      | Fungsi                                                                 |
|-------------|------------------------------------------------------------------------|
| `prepare`   | Membuat image kosong (misalnya `floppy.img`) sebagai media bootable.   |
| `bootloader`| Meng-assemble bootloader (biasanya dari file `.asm`).                  |
| `stdlib`    | Meng-compile pustaka dasar (`stdlib.c` atau sejenisnya).               |
| `shell`     | Meng-compile file shell CLI yang digunakan.                            |
| `kernel`    | Meng-compile file kernel utama dari OS buatan.                         |
| `link`      | Menggabungkan semua bagian menjadi satu binary yang bisa dieksekusi.   |
| `build`     | Shortcut: menjalankan semua target di atas secara berurutan.           |

🔄 Cara Penggunaan
Untuk menjalankan semua tahapan build secara otomatis:

```
make build
```
Biasanya ini akan menghasilkan file output seperti:

- `floppy.img`

- `kernel.bin`

- `bootloader.bin`

Image lengkap yang bisa dijalankan di Bochs atau QEMU.
