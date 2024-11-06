#include <stdio.h>
#include <string.h>

// Definisi struct untuk karakter Pegawai dan Pet
typedef struct {
    char name[50];
    int energy;
    int loves;
} Employee;

typedef struct {
    char name[50];
    int energy;
    int loves;
} Pet;

Employee employees[3] = {
    {"NAYLA", 55, 30},
    {"NAURA", 60, 15},
    {"IZZA", 75, 0}
};

Pet pets[3] = {
    {"PUTIH", 65, 30},
    {"MILLY", 25, 55},
    {"JOJO", 90, 60}
};

void show_attributes(char *name) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(name, employees[i].name) == 0) {
            printf("Atribut Pegawai %s:\n", employees[i].name);
            printf("Energy: %d\n", employees[i].energy);
            printf("Loves: %d\n", employees[i].loves);
            return;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (strcmp(name, pets[i].name) == 0) {
            printf("Atribut Pet %s:\n", pets[i].name);
            printf("Energy: %d\n", pets[i].energy);
            printf("Loves: %d\n", pets[i].loves);
            return;
        }
    }

    printf("Karakter dengan nama %s tidak ditemukan.\n", name);
}

void petting_pet(char *name) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(name, pets[i].name) == 0) {
            pets[i].loves += 10;
            printf("Anda mendapatkan lebih banyak kasih sayang dari %s!\n", pets[i].name);
            return;
        }
    }
    printf("Karakter %s tidak ditemukan atau bukan pet.\n", name);
}

void feed_employee(char *name) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(name, employees[i].name) == 0) {
            employees[i].energy += 10;
            printf("%s merasa lebih berenergi setelah makan!\n", employees[i].name);
            return;
        }
    }
    printf("Karakter %s tidak ditemukan atau bukan pegawai.\n", name);
}

int main() {
    char command[100];
    char action[50];
    char target[50];

    printf("Selamat datang di simulasi Pet Cafe!\n");
    printf("Masukkan perintah untuk melakukan aktivitas atau tampilkan atribut.\n");
    printf("Perintah yang tersedia:\n");
    printf("1. PETTING <NamaPet>\n");
    printf("2. FEED <NamaPegawai>\n");
    printf("3. ATTR <NamaKarakter>\n");
    printf("4. EXIT untuk keluar\n");

    while (1) {
        printf("\nMasukkan perintah: ");
        fgets(command, sizeof(command), stdin);
        sscanf(command, "%s %s", action, target);

        if (strcmp(action, "PETTING") == 0) {
            petting_pet(target);
        } else if (strcmp(action, "FEED") == 0) {
            feed_employee(target);
        } else if (strcmp(action, "ATTR") == 0) {
            show_attributes(target);
        } else if (strcmp(action, "EXIT") == 0) {
            printf("Keluar dari simulasi. Terima kasih!\n");
            break;
        } else {
            printf("Perintah tidak dikenali. Coba lagi.\n");
        }
    }

    return 0;
}
