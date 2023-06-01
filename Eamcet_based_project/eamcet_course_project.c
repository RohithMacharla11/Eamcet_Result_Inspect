#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char hallTicketNumber[15];
    char name[50];
    char fatherName[50];
    float marks;
    int rank;
    long int mobileNumber;
};

// Function to print the data of a student
void printStudent(struct Student student) {
    printf("\nHall Ticket Number: %s\n", student.hallTicketNumber);
    printf("Name: %s\n", student.name);
    printf("Father's Name: %s\n", student.fatherName);
    printf("Marks: %.2f\n", student.marks);
    printf("Rank: %d\n", student.rank);
    printf("Mobile Number: %ld\n", student.mobileNumber);
    printf("\n--------------------------------------------------------------------\n");
}

// Function to read and print all the data from the file
void printAllData() {
    FILE *file = fopen("eamcet.txt", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    struct Student student;

    while (fscanf(file, "%[^,],%[^,],%[^,],%f,%d,%ld%*c",
                  student.hallTicketNumber, student.name, student.fatherName,
                  &student.marks, &student.rank, &student.mobileNumber) == 6) {
        printStudent(student);
    }

    fclose(file);
}

// Function to compare ranks for sorting
int compareRanks(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;

    return studentA->rank - studentB->rank;
}

// Function to sort the data based on rank (lowest to highest)
void sortByRank() {
	int i;
    FILE *file = fopen("eamcet.txt", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    struct Student students[100];
    int count = 0;

    while (fscanf(file, "%[^,],%[^,],%[^,],%f,%d,%ld%*c",
                  students[count].hallTicketNumber, students[count].name,
                  students[count].fatherName, &students[count].marks,
                  &students[count].rank, &students[count].mobileNumber) == 6) {
        count++;
    }

    fclose(file);

    qsort(students, count, sizeof(struct Student), compareRanks);

    for (i = 0; i < count; i++) {
        printStudent(students[i]);
    }
}

// Function to search for a student by name
void searchByName(const char *name) {
    FILE *file = fopen("eamcet.txt", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    struct Student student;

    int found = 0;

    while (fscanf(file, " %[^,],%[^,],%[^,],%f,%d,%ld%*c",
                  student.hallTicketNumber, student.name, student.fatherName,
                  &student.marks, &student.rank, &student.mobileNumber) == 6) {
        // Remove the newline character from the name
        student.name[strcspn(student.name, "\n")] = '\0';

        if (strcmp(student.name, name) == 0) {
            printStudent(student);
            found = 1;
        }
    }

    if (!found) {
        printf("No student found with the given name.\n");
    }

    fclose(file);
}



// Function to search for a student by hall ticket number
int searchByHallTicketNumber(const char *hallTicketNumber) {
    FILE *file = fopen("eamcet.txt", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    struct Student student;

    int found = 0;

    while (fscanf(file, "%[^,],%[^,],%[^,],%f,%d,%ld%*c",
                  student.hallTicketNumber, student.name, student.fatherName,
                  &student.marks, &student.rank, &student.mobileNumber) == 6) {
        if (strcmp(student.hallTicketNumber, hallTicketNumber) == 0) {
            printStudent(student);
            return student.rank;
            found = 1;
            break; // Stop searching after finding the first match
        }
    }

    if (!found) {
        printf("No student found with the given hall ticket number.\n");
    }

    fclose(file);
}

int main() {
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Print all data\n");
        printf("2. Sort by rank (lowest to highest)\n");
        printf("3. Search by name\n");
        printf("4. Search by hall ticket number\n");
        printf("5. Search for which collages you are eligible\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printAllData();
                break;
            case 2:
                sortByRank();
                break;
            case 3:
                printf("Enter the name to search: ");
                char name[50];
                scanf(" %[^\n]", name);
                searchByName(name);
                break;
            case 4:
                printf("Enter the hall ticket number to search: ");
                char hallTicketNumber[15];
                int temp1;
                scanf(" %[^\n]", hallTicketNumber);
                temp1=searchByHallTicketNumber(hallTicketNumber);
                break;
            case 5: 
            printf("Enter the hall ticket number to search: ");
                char HallTicketNumber[15];
                int branch;
                int temp;
                scanf(" %[^\n]", HallTicketNumber);
                temp=searchByHallTicketNumber(HallTicketNumber);
//              printf("temp=%d",temp);
				printf("\nWhich branch are you intrested in : \n");
				printf("1. Chemical Engeneering\n");
				printf("2. Computer Science and Engeneering\n");
				printf("3. Electrical and Electronics Engeneering\n");
				printf("4. Electronics and Communication Engeneering\n");
				printf("5. Mechanical Engeneering\n");
				printf("6. Metallurgical Engeneering\n");
				printf("7. Information And Technology\n");
				scanf("%d",&branch);
				switch(branch){
				
				case 1 : //Chemical Engeneering
					if(temp>=1 && temp<15000){
						printf("\n\4JNTUH Collage of Engineering\n\4Osmania University\n\4Anurag University\n\4CBIT Collage\n\4CMR Collage of Engineering(2main campus)\n\4");
					}
					else if(temp>=15000 && temp<25000){
						printf("\n\4CMR collages(remaining 4 campusus)\n\4CVR Collage\n\4GRIET Collage\n\4KITSW collage\n\4 SR University\n\4Malla Reddy Collage.");
					}
					else if(temp>=25000 && temp<40000){
						printf("\n\4MRCET Collage\n\4KMIT Collage\n\4VNR VJIT Collage\n\4 Vardham Collage of Engineering\n\4Vignan Instute of Technology");
					}
					else if(temp>=40000 && temp<60000){
						printf("\n\4ACE Engineering Collage\n\4anurag Engineering Collage\n\4BVRIT Narsapur Collage\n\4GNITS For women\n\4Geethanjali Collage\n\4GuruNanak Instute of Technology");
					}
					else if(temp>=60000 && temp<80000){
						printf("\n\4GNITC Hyderabad\n\4HITAM Engineering Collage\n\4JBIET Engineering Collage\n\4KG Reddy Engineering Collage\n\4MGIT Engineering Collage");
					}
					else if(temp>=80000 && temp<100000){
						printf("\n\4MLR indtute of technology\n\4MIST Engineering Collage\n\44-Malla Reddy Secundrabad Instutes of technology\n\4Matrusri Engineering Collage");
					}
					else{
						printf("\n\4MVSR Engineering Collage\n\4Samskruthi Engineering Collage\n\4Sreenidhi Instute of Science and Technology\n\4Sreyas Instute of Engineering and  Tecchnology\n\4SPEC Engineering Collage");
					}
				break;
				case 2 : //Computer Science and Engeneering
					if(temp>=1 && temp<4000){
						printf("\n\4JNTUH Collage of Engineering\n\4Osmania University\n\4Anurag University\n\4CBIT Collage\n\4CMR Collage of Engineering(2main campus)\n\4");
					}
					else if(temp>=4000 && temp<10000){
						printf("\n\4CMR collages(remaining 4 campusus)\n\4CVR Collage\n\4GRIET Collage\n\4KITSW collage\n\4 SR University\n\4Malla Reddy Collage.");
					}
					else if(temp>=10000 && temp<18000){
						printf("\n\4MRCET Collage\n\4KMIT Collage\n\4VNR VJIT Collage\n\4 Vardham Collage of Engineering\n\4Vignan Instute of Technology");
					}
					else if(temp>=18000 && temp<30000){
						printf("\n\4ACE Engineering Collage\n\4anurag Engineering Collage\n\4BVRIT Narsapur Collage\n\4GNITS For women\n\4Geethanjali Collage\n\4GuruNanak Instute of Technology");
					}
					else if(temp>=30000 && temp<50000){
						printf("\n\4GNITC Hyderabad\n\4HITAM Engineering Collage\n\4JBIET Engineering Collage\n\4KG Reddy Engineering Collage\n\4MGIT Engineering Collage");
					}
					else if(temp>=50000 && temp<80000){
						printf("\n\4MLR indtute of technology\n\4MIST Engineering Collage\n\44-Malla Reddy Secundrabad Instutes of technology\n\4Matrusri Engineering Collage");
					}
					else{
						printf("\n\4MVSR Engineering Collage\n\4Samskruthi Engineering Collage\n\4Sreenidhi Instute of Science and Technology\n\4Sreyas Instute of Engineering and  Tecchnology\n\4SPEC Engineering Collage");
					}
				break;
				case 3 : //Electrical and Electronics Engeneering
					if(temp>=1 && temp<9000){
						printf("\n\4JNTUH Collage of Engineering\n\4Osmania University\n\4Anurag University\n\4CBIT Collage\n\4CMR Collage of Engineering(2main campus)\n\4");
					}
					else if(temp>=9000 && temp<15000){
						printf("\n\4CMR collages(remaining 4 campusus)\n\4CVR Collage\n\4GRIET Collage\n\4KITSW collage\n\4 SR University\n\4Malla Reddy Collage.");
					}
					else if(temp>=15000 && temp<25000){
						printf("\n\4MRCET Collage\n\4KMIT Collage\n\4VNR VJIT Collage\n\4 Vardham Collage of Engineering\n\4Vignan Instute of Technology");
					}
					else if(temp>=25000 && temp<40000){
						printf("\n\4ACE Engineering Collage\n\4anurag Engineering Collage\n\4BVRIT Narsapur Collage\n\4GNITS For women\n\4Geethanjali Collage\n\4GuruNanak Instute of Technology");
					}
					else if(temp>=40000 && temp<70000){
						printf("\n\4GNITC Hyderabad\n\4HITAM Engineering Collage\n\4JBIET Engineering Collage\n\4KG Reddy Engineering Collage\n\4MGIT Engineering Collage");
					}
					else if(temp>=70000 && temp<100000){
						printf("\n\4MLR indtute of technology\n\4MIST Engineering Collage\n\44-Malla Reddy Secundrabad Instutes of technology\n\4Matrusri Engineering Collage");
					}
					else{
						printf("\n\4MVSR Engineering Collage\n\4Samskruthi Engineering Collage\n\4Sreenidhi Instute of Science and Technology\n\4Sreyas Instute of Engineering and  Tecchnology\n\4SPEC Engineering Collage");
					}
				break;
				case 4 : //Electronics and Communication Engeneering
					if(temp>=1 && temp<3000){
						printf("\n\4JNTUH Collage of Engineering\n\4Osmania University\n\4Anurag University\n\4CBIT Collage\n\4CMR Collage of Engineering(2main campus)\n\4");
					}
					else if(temp>=3000 && temp<9000){
						printf("\n\4CMR collages(remaining 4 campusus)\n\4CVR Collage\n\4GRIET Collage\n\4KITSW collage\n\4 SR University\n\4Malla Reddy Collage.");
					}
					else if(temp>=9000 && temp<22000){
						printf("\n\4MRCET Collage\n\4KMIT Collage\n\4VNR VJIT Collage\n\4 Vardham Collage of Engineering\n\4Vignan Instute of Technology");
					}
					else if(temp>=22000 && temp<40000){
						printf("\n\4ACE Engineering Collage\n\4anurag Engineering Collage\n\4BVRIT Narsapur Collage\n\4GNITS For women\n\4Geethanjali Collage\n\4GuruNanak Instute of Technology");
					}
					else if(temp>=40000 && temp<75000){
						printf("\n\4GNITC Hyderabad\n\4HITAM Engineering Collage\n\4JBIET Engineering Collage\n\4KG Reddy Engineering Collage\n\4MGIT Engineering Collage");
					}
					else if(temp>=75000 && temp<100000){
						printf("\n\4MLR indtute of technology\n\4MIST Engineering Collage\n\44-Malla Reddy Secundrabad Instutes of technology\n\4Matrusri Engineering Collage");
					}
					else{
						printf("\n\4MVSR Engineering Collage\n\4Samskruthi Engineering Collage\n\4Sreenidhi Instute of Science and Technology\n\4Sreyas Instute of Engineering and  Tecchnology\n\4SPEC Engineering Collage");
					}
				break;
				case 5 : //Mechanical Engeneering
					if(temp>=1 && temp<6000){
						printf("\n\4JNTUH Collage of Engineering\n\4Osmania University\n\4Anurag University\n\4CBIT Collage\n\4CMR Collage of Engineering(2main campus)\n\4");
					}
					else if(temp>=6000 && temp<17000){
						printf("\n\4CMR collages(remaining 4 campusus)\n\4CVR Collage\n\4GRIET Collage\n\4KITSW collage\n\4 SR University\n\4Malla Reddy Collage.");
					}
					else if(temp>=17000 && temp<28000){
						printf("\n\4MRCET Collage\n\4KMIT Collage\n\4VNR VJIT Collage\n\4 Vardham Collage of Engineering\n\4Vignan Instute of Technology");
					}
					else if(temp>=28000 && temp<45000){
						printf("\n\4ACE Engineering Collage\n\4anurag Engineering Collage\n\4BVRIT Narsapur Collage\n\4GNITS For women\n\4Geethanjali Collage\n\4GuruNanak Instute of Technology");
					}
					else if(temp>=45000 && temp<60000){
						printf("\n\4GNITC Hyderabad\n\4HITAM Engineering Collage\n\4JBIET Engineering Collage\n\4KG Reddy Engineering Collage\n\4MGIT Engineering Collage");
					}
					else if(temp>=60000 && temp<90000){
						printf("\n\4MLR indtute of technology\n\4MIST Engineering Collage\n\44-Malla Reddy Secundrabad Instutes of technology\n\4Matrusri Engineering Collage");
					}
					else{
						printf("\n\4MVSR Engineering Collage\n\4Samskruthi Engineering Collage\n\4Sreenidhi Instute of Science and Technology\n\4Sreyas Instute of Engineering and  Tecchnology\n\4SPEC Engineering Collage");
					}
				break;
				case 6 :  //Metallurgical Engeneering
					if(temp>=1 && temp<3000){
						printf("\n\4JNTUH Collage of Engineering\n\4Osmania University\n\4Anurag University\n\4CBIT Collage\n\4CMR Collage of Engineering(2main campus)\n\4");
					}
					else if(temp>=3000 && temp<9000){
						printf("\n\4CMR collages(remaining 4 campusus)\n\4CVR Collage\n\4GRIET Collage\n\4KITSW collage\n\4 SR University\n\4Malla Reddy Collage.");
					}
					else if(temp>=9000 && temp<18000){
						printf("\n\4MRCET Collage\n\4KMIT Collage\n\4VNR VJIT Collage\n\4 Vardham Collage of Engineering\n\4Vignan Instute of Technology");
					}
					else if(temp>=18000 && temp<39000){
						printf("\n\4ACE Engineering Collage\n\4anurag Engineering Collage\n\4BVRIT Narsapur Collage\n\4GNITS For women\n\4Geethanjali Collage\n\4GuruNanak Instute of Technology");
					}
					else if(temp>=39000 && temp<59000){
						printf("\n\4GNITC Hyderabad\n\4HITAM Engineering Collage\n\4JBIET Engineering Collage\n\4KG Reddy Engineering Collage\n\4MGIT Engineering Collage");
					}
					else if(temp>=59000 && temp<70000){
						printf("\n\4MLR indtute of technology\n\4MIST Engineering Collage\n\44-Malla Reddy Secundrabad Instutes of technology\n\4Matrusri Engineering Collage");
					}
					else{
						printf("\n\4MVSR Engineering Collage\n\4Samskruthi Engineering Collage\n\4Sreenidhi Instute of Science and Technology\n\4Sreyas Instute of Engineering and  Tecchnology\n\4SPEC Engineering Collage");
					}
				break;
				case 7 : //Civil Engeneering
					if(temp>=1 && temp<3000){
						printf("\n\4JNTUH Collage of Engineering\n\4Osmania University\n\4Anurag University\n\4CBIT Collage\n\4CMR Collage of Engineering(2main campus)\n\4");
					}
					else if(temp>=3000 && temp<9000){
						printf("\n\4CMR collages(remaining 4 campusus)\n\4CVR Collage\n\4GRIET Collage\n\4KITSW collage\n\4 SR University\n\4Malla Reddy Collage.");
					}
					else if(temp>=9000 && temp<18000){
						printf("\n\4MRCET Collage\n\4KMIT Collage\n\4VNR VJIT Collage\n\4 Vardham Collage of Engineering\n\4Vignan Instute of Technology");
					}
					else if(temp>=18000 && temp<39000){
						printf("\n\4ACE Engineering Collage\n\4anurag Engineering Collage\n\4BVRIT Narsapur Collage\n\4GNITS For women\n\4Geethanjali Collage\n\4GuruNanak Instute of Technology");
					}
					else if(temp>=40000 && temp<60000){
						printf("\n\4GNITC Hyderabad\n\4HITAM Engineering Collage\n\4JBIET Engineering Collage\n\4KG Reddy Engineering Collage\n\4MGIT Engineering Collage");
					}
					else if(temp>=60000 && temp<75000){
						printf("\n\4MLR indtute of technology\n\4MIST Engineering Collage\n\44-Malla Reddy Secundrabad Instutes of technology\n\4Matrusri Engineering Collage");
					}
					else{
						printf("\n\4MVSR Engineering Collage\n\4Samskruthi Engineering Collage\n\4Sreenidhi Instute of Science and Technology\n\4Sreyas Instute of Engineering and  Tecchnology\n\4SPEC Engineering Collage");
					}
				break;
				case 8 : //Information And Technology
					if(temp>=1 && temp<4000){
						printf("\n\4JNTUH Collage of Engineering\n\4Osmania University\n\4Anurag University\n\4CBIT Collage\n\4CMR Collage of Engineering(2main campus)\n\4");
					}
					else if(temp>=4000 && temp<10000){
						printf("\n\4CMR collages(remaining 4 campusus)\n\4CVR Collage\n\4GRIET Collage\n\4KITSW collage\n\4 SR University\n\4Malla Reddy Collage.");
					}
					else if(temp>=10000 && temp<18000){
						printf("\n\4MRCET Collage\n\4KMIT Collage\n\4VNR VJIT Collage\n\4 Vardham Collage of Engineering\n\4Vignan Instute of Technology");
					}
					else if(temp>=18000 && temp<30000){
						printf("\n\4ACE Engineering Collage\n\4anurag Engineering Collage\n\4BVRIT Narsapur Collage\n\4GNITS For women\n\4Geethanjali Collage\n\4GuruNanak Instute of Technology");
					}
					else if(temp>=30000 && temp<50000){
						printf("\n\4GNITC Hyderabad\n\4HITAM Engineering Collage\n\4JBIET Engineering Collage\n\4KG Reddy Engineering Collage\n\4MGIT Engineering Collage");
					}
					else if(temp>=50000 && temp<80000){
						printf("\n\4MLR indtute of technology\n\4MIST Engineering Collage\n\44-Malla Reddy Secundrabad Instutes of technology\n\4Matrusri Engineering Collage");
					}
					else{
						printf("\n\4MVSR Engineering Collage\n\4Samskruthi Engineering Collage\n\4Sreenidhi Instute of Science and Technology\n\4Sreyas Instute of Engineering and  Tecchnology\n\4SPEC Engineering Collage");
					}
				break;
			}
			break;	
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");

    } while (choice != 6);

    return 0;
}

