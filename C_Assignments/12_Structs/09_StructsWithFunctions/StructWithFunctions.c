#include <stdio.h>

// DEFINING STRUCT
struct MyData
{
    int i;
    float f;
    double d;
    char c;
};

int main(void)
{
    // Function prototype
    struct MyData AddStructMembers(struct MyData, struct MyData, struct MyData);

    // Variable declarations
    struct MyData data1_vtg, data2_vtg, data3_vtg, answer_data_vtg;

    // code
    //  *** data1 ***
    printf("\n\n\n\n");
    printf("********** Data1 **********\n\n");
    printf("Enter integer value for 'i' of 'struct MyData data1': ");
    scanf("%d", &data1_vtg.i);

    printf("\n\n");
    printf("Enter floating-point value for 'f' of 'struct MyData data1': ");
    scanf("%f", &data1_vtg.f);

    printf("\n\n");
    printf("Enter 'double' value for 'd' of 'struct MyData data1': ");
    scanf("%lf", &data1_vtg.d);

    printf("\n\n");
    printf("Enter character value for 'c' of 'struct MyData data1': ");
    data1_vtg.c = getch();
    printf("%c", data1_vtg.c);

    // *** data2 ***
    printf("\n\n\n\n");
    printf("********** Data2 **********\n\n");
    printf("Enter integer value for 'i' of 'struct MyData data2': ");
    scanf("%d", &data2_vtg.i);

    printf("\n\n");
    printf("Enter floating-point value for 'f' of 'struct MyData data2': ");
    scanf("%f", &data2_vtg.f);

    printf("\n\n");
    printf("Enter 'double' value for 'd' of 'struct MyData data2': ");
    scanf("%lf", &data2_vtg.d);

    printf("\n\n");
    printf("Enter character value for 'c' of 'struct MyData data2': ");
    data2_vtg.c = getch();
    printf("%c", data2_vtg.c);

    // *** data3 ***
    printf("\n\n\n\n");
    printf("********** Data3 **********\n\n");
    printf("Enter integer value for 'i' of 'struct MyData data3': ");
    scanf("%d", &data3_vtg.i);

    printf("\n\n");
    printf("Enter floating-point value for 'f' of 'struct MyData data3': ");
    scanf("%f", &data3_vtg.f);

    printf("\n\n");
    printf("Enter 'double' value for 'd' of 'struct MyData data3': ");
    scanf("%lf", &data3_vtg.d);

    printf("\n\n");
    printf("Enter character value for 'c' of 'struct MyData data3': ");
    data3_vtg.c = getch();
    printf("%c", data3_vtg.c);

    // *** CALLING FUNCTION AddStructMembers ***
    // This function accepts three variables of type 'struct MyData' as parameters,
    // adds up the respective members, and returns the answer in another struct of the same type.
    answer_data_vtg = AddStructMembers(data1_vtg, data2_vtg, data3_vtg);

    printf("\n\n\n\n");
    printf("********** Answer *********\n\n");
    printf("answer_data.i = %d\n", answer_data_vtg.i);
    printf("answer_data.f = %f\n", answer_data_vtg.f);
    printf("answer_data.d = %lf\n\n", answer_data_vtg.d);

    answer_data_vtg.c = data1_vtg.c;
    printf("answer_data.c (from data1) = %c\n\n", answer_data_vtg.c);

    answer_data_vtg.c = data2_vtg.c;
    printf("answer_data.c (from data2) = %c\n\n", answer_data_vtg.c);

    answer_data_vtg.c = data3_vtg.c;
    printf("answer_data.c (from data3) = %c\n\n", answer_data_vtg.c);

    return 0;
}

struct MyData AddStructMembers(struct MyData md_one, struct MyData md_two, struct MyData md_three)
{
    // Variable declarations
    struct MyData answer;

    // Code
    answer.i = md_one.i + md_two.i + md_three.i;
    answer.f = md_one.f + md_two.f + md_three.f;
    answer.d = md_one.d + md_two.d + md_three.d;

    return answer;
}