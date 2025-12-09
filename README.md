# 🩺 MINI HEALTH TRACKER & HYDRATION REMINDER

Program konsol sederhana yang dikembangkan menggunakan C++ untuk melacak dan memberikan rekomendasi kesehatan harian, meliputi asupan air, langkah kaki, dan durasi tidur.

---

## 📝 INFORMASI UJIAN

| Keterangan        | Detail                      |
| :---------------- | :-------------------------- |
| **Ujian**         | Ujian Tengah Semester (UTS) |
| **Mata Kuliah**   | Algoritma dan Pemrograman   |
| **Kelas**         | IF107                       |
| **Program Studi** | PJJ Informatika S1          |
| **Nama**          | Bintang Triadmaja           |
| **NIM**           | 250401010075                |

---

## ✨ FITUR UTAMA

Program ini berfungsi sebagai pelacak kesehatan mingguan dengan empat fitur utama:

1.  **Input Data Harian**: Memungkinkan pengguna memasukkan data Air (gelas), Langkah Kaki (jumlah), dan Tidur (jam) untuk hari tertentu (1-7).
2.  **Lihat Statistik Mingguan**: Menampilkan tabel ringkasan data untuk 7 hari dan menghitung **rata-rata harian** dari ketiga metrik.
3.  **Cek Rekomendasi Kesehatan**: Memberikan saran dan status perbandingan antara rata-rata data pengguna dengan target kesehatan ideal (misalnya, 8 gelas air/hari, 5000 langkah/hari).
4.  **Reset Data**: Mengosongkan semua data yang tersimpan untuk memulai pelacakan dari awal.

---

## 🛠️ PANDUAN PENGGUNAAN (C++)

### 1. Prasyarat

- **Compiler C++**: Dianjurkan menggunakan **g++** (GNU C++ Compiler), yang umum tersedia di Linux (WSL, Ubuntu) atau melalui MinGW di Windows.

### 2. Kompilasi Program

Disini program yang sudah dikompilasi sudah tersedia di folder `build/`. Namun, jika Anda ingin mengkompilasi ulang kode sumber, ikuti langkah berikut:

Jika Anda berada di terminal Linux (WSL, Ubuntu) atau menggunakan MinGW:

```bash
# Gunakan g++ untuk mengkompilasi file C++
g++ ./src/main.cpp -o ./build/MiniHealthApp
```

```plaintext
# Catatan: Menggunakan 'gcc' akan menyebabkan error 'undefined reference'
```

### 3. Menjalankan Program

Setelah kompilasi berhasil, jalankan program dengan perintah berikut:

```bash
./build/MiniHealthApp
```
