# 🎲 UAS-AP_MINESWEEPER_LITE

##  Nama Kelompok: [OH]

### 🧑‍💻 Anggota Kelompok:
1. Nama Anggota 1 (NIM)
2. Nama Anggota 2 (NIM)
3. Nama Anggota 3 (NIM)
4. Nama Anggota 4 (NIM)

---

## 📝 Deskripsi Program

Game ini merupakan simulasi permainan **Minesweeper Lite berbasis C++ (CLI)** yang dimainkan pada terminal (command line). Ukuran papan adalah 5x5 dan jumlah bom acak sebanyak 5.

Pemain akan memilih baris dan kolom untuk membuka sel. Jika pemain membuka sel yang berisi bom, maka game selesai. Jika tidak, pemain harus membuka semua sel non-bom untuk menang.

Permainan ini juga menampilkan jumlah bom di sekitar sel yang aman (seperti game Minesweeper klasik).

---

### ✅ Fitur Utama:

- Papan 5x5 dengan bom acak
- Input pemain (baris dan kolom)
- Sistem buka sel otomatis jika kosong (zero adjacent bomb)
- Game selesai jika terkena bom atau menang
- Tampilan papan sebelum dan sesudah game

---

## 🚀 Cara Menjalankan Program

### Compile:
```bash
g++ minesweeper_lite.cpp -o minesweeper
