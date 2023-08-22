#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum loaisanpham
{
    CLOTHING,
    FOOTWEAR,
    ELECTRONICS
};
union thongtinsanpham
{
    char size[100];
    float weight;
};
typedef struct 
{
    char name[100];
    float price;
    enum loaisanpham type;
    union thongtinsanpham info;
} sanpham;
int main()
{
    int a;
    enum loaisanpham CLOTHING = 0;
    enum loaisanpham FOOTWEAR = 1;
    enum loaisanpham ELECTRONICS = 2;
    printf("Enter the number of products: ");
    scanf("%d", &a);
    sanpham products[a];
    // Khai báo mảng "products" để lưu trữ thông tin sản phẩm, với kích thước là biến a phụ thuộc vào ta nhập vào
    for (int i = 0; i < a; i++) //Chạy vòng lặp nhằm nhập thông tin sản phẩm
    {
        printf("\nEnter information for product %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", products[i].name);

        printf("Price: ");
        scanf("%f", &products[i].price);

        printf("Type (0: Clothing, 1: Footwear, 2: Electronics): ");
        int type;
        scanf("%d", &type);
        products[i].type = type;
    // Nhập loại sản phẩm thông qua nhập tay, sau đó gán giá trị cho "type" của sản phẩm.
        if (products[i].type == CLOTHING || products[i].type == FOOTWEAR) // Kiểm tra xem loại sản phẩm được nhập vào là CLOTHING hay FOOTWEAR
        {
            printf("Size: ");
            scanf("%s", products[i].info.size); // Nhập kích thước sản phẩm
        } 
        else if (products[i].type == ELECTRONICS) 
        {
            printf("Weight: ");
            scanf("%f", &products[i].info.weight); // Nhập cân nặng sản phẩm
        }
    }
    char b[100];
    printf("\nEnter the name of the product to retrieve information: ");
    scanf("%s", b);
     // Nhập tên sản phẩm cần tra cứu, sử dụng biến b là biến để nhập vào
    printf("\nProduct Information:\n");
    for (int i = 0; i < a; i++) // Vòng lặp nhập và duyệt sản phẩm cần tra cứu
    {
        if (strcmp(products[i].name, b) == 0) 
        /*Kiểm tra xem tên sản phẩm trong mảng products tại vị trí i có trùng với chuỗi b mà người dùng nhập hay không. Nếu trùng nhau 
        (trả về giá trị 0 từ hàm strcmp), thì một sản phẩm có tên tương tự đã được tìm thấy và ta có thể hiển thị thông tin của sản phẩm 
        này*/
        {
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2f\n", products[i].price); //Hiển thị giá của sản phẩm tại vị trí i, với định dạng số thập phân có hai chữ số sau dấu thập phân
            
            if (products[i].type == CLOTHING) 
            {
                printf("Type: Clothing\n");
                printf("Size: %s\n", products[i].info.size);
                //Nếu sản phẩm là loại quần áo, ta hiển thị loại sản phẩm là "Clothing" và hiển thị kích cỡ của sản phẩm thông qua products[i].info.size
            } 
            else if (products[i].type == FOOTWEAR) 
            {
                printf("Type: Footwear\n");
                printf("Size: %s\n", products[i].info.size);
                //Nếu sản phẩm là loại giày dép, ta hiển thị loại sản phẩm là "Footware" và hiển thị kích cỡ của sản phẩm thông qua products[i].info.size
            } 
            else if (products[i].type == ELECTRONICS) 
            {
                printf("Type: Electronics\n");
                printf("Weight: %.2f\n", products[i].info.weight);
                //Nếu sản phẩm là loại đồ điện tử, ta hiển thị loại sản phẩm là "Electronics" và hiển thị cân nặng của sản phẩm thông qua products[i].info.weight
            }
        }
    }
    return 0;
}
