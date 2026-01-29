/**
* Example with command line arguments.
* Will read name of student, student ID, coures, and campus from command line
* and then add that info to a csv file.
* if student name isn't given, will use ID to find it.
* If student ID isn't given, will use name to find it.
* if it can't find either, will print error and exit.
* uses the command line argument to also
* allow for printing the contents of the csv file.
* in a pretty print format.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    char student_id[20];
    char course[50];
    char campus[50];
} StudentRecord;

void set_new_record(StudentRecord* record, const char* name, const char* student_id, const char* course, const char* campus) {
    strncpy(record->name, name, sizeof(record->name) - 1);
    record->name[sizeof(record->name) - 1] = '\0';
    strncpy(record->student_id, student_id, sizeof(record->student_id) - 1);
    record->student_id[sizeof(record->student_id) - 1] = '\0';
    strncpy(record->course, course ? course : "N/A", sizeof(record->course) - 1);
    record->course[sizeof(record->course) - 1] = '\0';
    strncpy(record->campus, campus ? campus : "N/A", sizeof(record->campus) - 1);
    record->campus[sizeof(record->campus) - 1] = '\0';
}

// pretty print a record
void print_record(const StudentRecord* record) {
    printf("Name: %s\n", record->name);
    printf("Student ID: %s\n", record->student_id);
    printf("Course: %s\n", record->course);
    printf("Campus: %s\n", record->campus);
    printf("-------------------------\n");
}

char* find_name_by_id(StudentRecord* records, int record_count, const char* student_id) {
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].student_id, student_id) == 0) {
            return records[i].name;
        }
    }
    return NULL;
}

char* find_id_by_name(StudentRecord* records, int record_count, const char* name) {
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].name, name) == 0) {
            return records[i].student_id;
        }
    }
    return NULL;
}

void print_all(const StudentRecord* records, int record_count) {
    for (int i = 0; i < record_count; i++) {
        print_record(&records[i]);
    }
}

// read in the csv file for use, just store StudentRecords in an array
StudentRecord* read_csv(const char* filename, int* record_count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        *record_count = 0;
        return NULL;
    }
    StudentRecord* records = NULL;
    char line[200];
    *record_count = 0;
    while (fgets(line, sizeof(line), file)) {
        records = realloc(records, sizeof(StudentRecord) * (*record_count + 1));
        sscanf(line, "%49[^,],%19[^,],%49[^,],%49[^\n]", records[*record_count].name,
                records[*record_count].student_id,
                records[*record_count].course,
                records[*record_count].campus);
          (*record_count)++;
    }
    fclose(file);
    return records;
}

// write a new record to the csv file
void write_csv(const char* filename, const StudentRecord* record) {

}




// ok, now lets break up the processing of the arguments
void print_help() {
    printf("Usage: command_line [options]\n");
    printf("Options:\n");
    printf("  --name <name>          Student name\n");
    printf("  --id <student_id>      Student ID\n");
    printf("  --course <course>      Course name\n");
    printf("  --campus <campus>      Campus name\n");
    printf("  --print                Print all records\n");
    printf("  --help                 Show this help message\n");
}











int main(int argc, char* argv[]) {
    // if (has_help(argc, argv)) {
    //     print_help();
    //     return EXIT_SUCCESS;
    // }

    // const char* filename = "students.csv";

    // int record_count = 0;
    // StudentRecord* records = read_csv(filename, &record_count);

    // if (has_print(argc, argv)) {
    //     print_all(records, record_count);
    //     free(records);
    //     return EXIT_SUCCESS;
    // }



    // char* name = get_arg_value(argc, argv, "--name");
    // char* student_id = get_arg_value(argc, argv, "--id");
    // char* course = get_arg_value(argc, argv, "--course");
    // char* campus = get_arg_value(argc, argv, "--campus");

    // // Buffers for prompted input
    // char name_buf[50];
    // char id_buf[20];
    // char course_buf[50];
    // char campus_buf[50];

    // // Try to find missing name/id from existing records
    // if (!name && student_id) {
    //     name = find_name_by_id(records, record_count, student_id);
    // } else if (!student_id && name) {
    //     student_id = find_id_by_name(records, record_count, name);
    // }

    // // Prompt for any missing fields
    // if (!name) {
    //     name = prompt_for_input("Enter name: ", name_buf, sizeof(name_buf));
    // }
    // if (!student_id) {
    //     student_id = prompt_for_input("Enter student ID: ", id_buf, sizeof(id_buf));
    // }
    // if (!course) {
    //     course = prompt_for_input("Enter course: ", course_buf, sizeof(course_buf));
    // }
    // if (!campus) {
    //     campus = prompt_for_input("Enter campus: ", campus_buf, sizeof(campus_buf));
    // }

    // Validate required fields
    // if (!name || !student_id) {
    //     printf("Error: Name and student ID are required.\n");
    //     free(records);
    //     return EXIT_FAILURE;
    // }

    // StudentRecord new_record;
    // set_new_record(&new_record, name, student_id, course, campus);

    // write_csv(filename, &new_record);
    // printf("Record added successfully:\n");
    // print_record(&new_record);

    // free(records);
    return EXIT_SUCCESS;
}
