#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

bool flag = false;
const int arrSize = 100;
int productCount = 210;
int count = 0;
const int size = 300;
const int orderSize = 100;
int orderCount = 0;

string users[arrSize];
string passwords[arrSize];
string roles[arrSize];
string customerOrders[orderSize];
string customerUserNAmes[orderSize];
int customerBills[orderSize];

string categories[size] = {"grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", 
            "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", 
            "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", "grocery", 
            "grocery", "grocery", "crockery", "crockery", "crockery", "crockery", "crockery", "crockery", "crockery", "crockery", "crockery", "crockery", "electronics", "electronics", "electronics", "electronics", 
            "electronics", "electronics", "electronics", "electronics", "electronics", "electronics", "electronics", "electronics", "electronics", "electronics", "electronics", "electronics", "electronics", 
            "electronics", "electronics", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", 
            "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", "homeDecor", 
            "homeDecor", "homeDecor", "sports", "sports", "sports", "sports", "sports", "sports", "sports", "sports", "sports", "sports", "sports", "sports", "skincareOrBeautyProducts", "skincareOrBeautyProducts", 
            "skincareOrBeautyProducts", "skincareOrBeautyProducts", "skincareOrBeautyProducts", "skincareOrBeautyProducts", "skincareOrBeautyProducts", "skincareOrBeautyProducts", "pharmaceuticals", "pharmaceuticals",
            "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", 
            "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", 
            "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", 
            "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", 
            "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", 
            "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "pharmaceuticals", "stationery", "stationery", "stationery", "stationery", 
            "stationery", "stationery", "stationery", "stationery", "stationery", "stationery", "stationery"};

string productName[size] = {"chicken", "mutton", "beef", "chocolateCookies", "butterCookies", "fruitCake", "chocolateCake", "spongeCake", "cakeRusk", "breadS", "breadM", "breadL", "chocolateMuffins", "mangoMuffins",
              "chocolateDonuts", "milk", "cheddarCheese", "mozarellaCheese", "butter", "peanutButter", "cream", "paneer", "water", "greenTea", "tea", "coffee", "coldDrinks", "energyDrinks", "rice", "wheat", "maize",
               "oats", "beans", "peas", "lentils", "apple", "orange", "banana", "guava", "grapes", "cherry", "pomegranate", "avacado", "pineApple", "onions", "garlic", "ginger", "potato", "tomato", "cucumber", 
               "ladyFinger", "cabbage", "carrot", "cauliflower", "eggPlant", "turnip", "bittergaurd", "dinnerSet", "teaSet", "icecreamSet", "soupSet", "roundTray", "toothPickHolder", "serviceTray", "glassRack", 
               "waterBottles", "iceContainer", "invertor", "airConditioner", "washingMachine", "LED", "vaccumCleaner", "microwaveOven", "waterPurifier", "desktop", "CPU", "laptop", "tablet", "mobilePhone", "keyboard",
                "mouse", "printer", "watches", "laptopCharger", "phoneCharger", "airpods", "tiles", "woodenTiles", "carpet", "trashCan", "bathMats", "doorMats", "sofa", "diningChairs", "lawnChairs", "tables", 
                "diningTable", "tablesForLivingRoom", "fileCabinet", "bookShelf", "vases", "candles", "pictureFrames", "tableLamp", "floorLamp", "chandelier", "ceilingLights", "artificialPlants", "curtain", 
                "wallpaper", "paint", "mirror", "wallMountedBaskets", "coatHooks", "toothbrushHolder", "wallClock", "boxingGloves", "boxingBag", "cycle", "helmet", "football", "basketball", "badmintonSet", 
                "cricketKit", "skipingRope", "ludo", "chess", "tableTennis", "bodyMoisturizer", "scrub", "cleanser", "deodorants", "lipstick", "foundation", "eyeShades", "eyeliner", "ibuprofen", "aspirin", 
                "panadol", "cetirizine", "naproxen", "metformin", "amoxicillin", "rivoban", "ascard", "genopra", "azithromycin", "lactobacillus", "omega3", "ginseng", "fishOil", "osliaD3", "ezomol", "oratane", 
                "insulin", "vitaminB12", "corticosteroids", "penicillinG", "ceftriaxone", "metronidazole", "adrenaline", "roseWater", "vitaminE", "optivarDrops", "murineplusDrops", "patanolDrops", "debroxDrops", 
                "earwaxMDdrops", "micatinDrops", "otomaxDrops", "corexD", "arinac", "cufex", "hydryllin", "broxol", "gastronil", "antial", "britanyl", "EasthamaSyrup", "brufen", "panadolLiquid", "betnovate", 
                "aloveraGel", "zinOxideOintment", "calaminLotion", "hydrocorticoneCream", "arynoinplusGel", "pyodine", "multivitamins", "vitaminD", "vitaminC", "calciumSuppliments", "surbexZ", "vitaminBcomplex", 
                "folicAcidB9", "bandages", "gauze", "antisepticWipes", "coldPacks", "tweezers", "scissors", "notePads", "acrylics", "oilPaints", "pens", "pencilColors", "markerColors", "schoolBags", "diaries", "eraser",
                 "sharpener", "geometryBox"};

int productPrice[size] = {670, 1800, 1200, 1000, 1200, 200, 300, 150, 50, 70, 150, 250, 50, 50, 50, 200, 450, 470, 400, 600, 250, 300, 70, 150, 900, 1200, 120, 80, 190, 500, 300, 395, 160, 75, 320, 230, 90, 250, 170, 
            125, 349, 760, 730, 320, 240, 120, 129, 80, 70, 40, 75, 50, 30, 55, 40, 60, 55, 15000, 4000, 3400, 9000, 1100, 500, 400, 1500, 1200, 700, 70000, 121000, 15000, 126000, 9000, 9000, 8000, 117000, 10000,
             700000, 700000, 50000, 1700, 300, 40000, 5000, 2000, 500, 3000, 90, 120, 2000, 300, 200, 200, 20000, 22000, 5000, 6000, 9000, 5000, 2000, 5000, 2000, 500, 2000, 5000, 6000, 10000, 10000, 2000, 5000, 
             500, 1200, 7000, 500, 2000, 600, 2000, 3000, 2000, 10000, 5000, 2000, 2000, 1000, 5000, 2000, 500, 2000, 5000, 500, 600, 200, 500, 500, 2000, 1000, 500, 25, 30, 25, 200, 150, 200, 70, 200, 300, 250, 
             50, 75, 70, 200, 300, 250, 150, 200, 70, 60, 55, 100, 100, 100, 200, 150, 75, 55, 55, 200, 250, 175, 185, 90, 50, 85, 75, 250, 100, 90, 65, 90, 200, 100, 150, 75, 150, 300, 350, 250, 350, 400, 200, 
             250, 250, 250, 200, 250, 300, 200, 200, 250, 250, 350, 500, 100, 5000, 5000, 200, 500, 500, 2000, 50, 50, 500};

void clearScreen();
void header();
int loginMenu();

bool signIn(string username, string password);
void signUp(string username, string password, string role);
void storeLogInData(string username, string password, string role);
void loadLogInData();
string getParse(string line, int num);
bool isValid(string username);
string getRole(string username);


void adminInterface();
void customerInterface();
void employeeInterface();

void adminChoice();
void customerChoice();
void employeeChoice();

void category();
void addProduct();
bool checkProductUpdate(string pName);
void updateProductPrice();
bool checkProductPriceUpdate(string pName, int newPrice);
void deleteProduct();
bool checkProductDelete(string pCategory, string pName);
void storeProducts(string productCategory, string pName, int pPrice);
void loadProducts();

void product();
int customerOrder();
void addCustomerOrder(string customerName, string order, int bill);
void storeOrders(string customerName, string order, int bill);
void loadOrderData();
void paymentOption();

void checkOrder();
void viewOrders();

main()
{
    loadLogInData();
    loadProducts();
    loadOrderData();
    while (true)
    {
        int log = 0;
        system("cls");
        header();

        log = loginMenu();
        if (log == 1)
        {
            string username;
            string password;
            bool check;
            string role;
            system("cls");
            header();
            cout << "Enter UserName: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter your Role: ";
            cin >> role;

            check = isValid(username);
            if (check == false)
            {
                signUp(username, password, role);
            }
            else if (check == true)
            {
                cout << "      > USER ALREADY EXISTS!!! TRY OTHER NAME!!" << endl;
            }
            clearScreen();
        }
        else if (log == 2)
        {
            string username;
            string password;
            string role;
            bool valid;

            system("cls");
            header();
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            valid = signIn(username, password);

            if (valid == true)
            {
                role = getRole(username);

                if (role == "admin")
                {
                    system("cls");
                    adminInterface();
                    adminChoice();
                }
                else if (role == "customer")
                {
                    flag = true;
                    system("cls");
                    customerInterface();
                    customerChoice();
                }
                else if (role == "employee")
                {
                    system("cls");
                    employeeInterface();
                    employeeChoice();
                }
            }
            else if (valid == false)
            {
                cout << "       > You have Entered Wrong Information!! TRY AGAIN!!" << endl;
            }
            clearScreen();
        }

        else if (log == 3)
        {
            clearScreen();
            cout << endl << endl << endl << endl << endl << endl;
            cout << "         > Thank You for using this Software!!!";
            cout << endl;
            break;
        }
    }
}

void clearScreen()
{
    cout << "Press Any key to Continue: ";
    getch();
    system("cls");
}

void header()
{
    cout << endl << endl << endl;
    cout << " *****************************************************************" << endl;
    cout << " *                 SUPERMARKET MANAGEMENT SYSTEM                 *" << endl;
    cout << " *                                                               *" << endl;
    cout << " *****************************************************************" << endl;
    cout << endl
         << endl;
}

int loginMenu()
{
    int option;
    cout << endl;
    cout << "________________________"<< endl;
    cout << "|       LOGIN MENU     |" << endl;
    cout << "-------------------------" << endl;
    cout << "1. SignUp" << endl;
    cout << "2. SignIn" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
    cout << "Enter your Choice: ";
    cin >> option;
    return option;
}

bool signIn(string username, string password)
// this function will check if the user provides correct information will signing in
{
    bool check = false;
    for (int idx = 0; idx < count; idx++)
    {
        if (users[idx] == username && passwords[idx] == password)
        {
            check = true;
        }
    }
    return check;
}

void signUp(string username, string password, string role)
// this function will store the user information in arrays
{
    if (count < arrSize)
    {
        users[count] = username;
        passwords[count] = password;
        roles[count] = role;
        count++;
        storeLogInData(username, password, role);

        cout << "          > SIGNED UP SUCCESSFULLY!!" << endl;
    }
    else
    {
        cout << "       > USER CAPACITY EXCEEDED!!" << endl;
    }
}

void storeLogInData(string username, string password, string role)
// this function will store user login data in file
{
    fstream file;
    file.open("logInData.txt", ios::app);
    file << username << "," << password << "," << role << endl; 
    file.close();
}

void loadLogInData()
// this function will read login data from file and will load it when the program starts
{
    fstream file;
    string record;
    file.open("logInData.txt", ios::in);
    while(getline(file, record))
    {
        users[count] = getParse(record, 1);
        passwords[count] = getParse(record, 2);
        roles[count] = getParse(record, 3);
        count++;
    }
    file.close();
}

string getParse(string record, int num)
// this function will divide the record stored in file in parts according to our requirement
{
    int count = 1;
    string word;
    for (int i = 0; i < record.length(); i++)
    {
        if (record[i] == ',')
        {
            count = count + 1;
        }
        else if (count == num)
        {
            word = word + record[i];
        }
    }
    return word;
}

bool isValid(string username)
// this function will check if the username is unique or not
{
    bool check = false;
    for (int i = 0; i < count; i++)
    {
        if (users[i] == username)
        {
            check = true;
            break;
        }
    }
    return check;
}

string getRole(string username)
// this function will take username and will return its role
{
    for (int idx = 0; idx < arrSize; idx++)
    {
        if (username == users[idx])
        {
            return roles[idx];
        }
    }
}

void adminInterface()
// this function just show the menu for admin
{
    cout << endl;
    cout << "________________________"<< endl;
    cout << "|        ADMIN MENU     |" << endl;
    cout << "-------------------------" << endl;
    cout << " 1. View List of Products" << endl;
    cout << " 2. Add Product" << endl;
    cout << " 3. Update Product Rate" << endl;
    cout << " 4. Delete Product" << endl;
    cout << " 5. View Orders" << endl;
    cout << " 6. Logout" << endl;
    cout << endl;
}

void customerInterface()
// this function just show the menu for customer
{
    cout << endl;
    cout << "________________________"<< endl;
    cout << "|     CUSTOMER MENU     |" << endl;
    cout << "-------------------------" << endl;
    cout << " 1. View List of Products" << endl;
    cout << " 2. Make Order" << endl;
    cout << " 3. Payment Options" << endl;
    cout << " 4. Logout" << endl;
    cout << endl;
}

void employeeInterface()
// this function just show the menu for employee
{
    cout << endl;
    cout << "________________________"<< endl;
    cout << "|   EMPLOYEE MENU      |" << endl;
    cout << "-------------------------" << endl;
    cout << " 1. Check Orders" << endl;
    cout << " 2. View Details of Customers" << endl;
    cout << " 3. Logout" << endl;
    cout << endl;
}

void adminChoice()
// this will take admin choice and will show according to his choice
{
    int choice;
    cout << "Enter your Choice: ";
    cin >> choice;
    clearScreen();

    if (choice == 1)
    {
        system("cls");
        category();
        product();
        adminInterface();
        adminChoice();
    }
    else if (choice == 2)
    {
        system("cls");
        addProduct();
        adminInterface();
        adminChoice();
    }
    else if (choice == 3)
    {
        system("cls");
        updateProductPrice();
        adminInterface();
        adminChoice();
    }
    else if (choice == 4)
    {
        system("cls");
        deleteProduct();
        adminInterface();
        adminChoice();
    }
    else if (choice == 5)
    {
        system("cls");
        viewOrders();
        cout << endl;
        clearScreen();
        adminInterface();
        adminChoice();
    }
   // else if (choice == 6)
    //  {
    //    system("cls");
    //   header();
    // int log = loginMenu();
    //}
}

void customerChoice()
// this will take customer choice and will show according to his choice
{
    int bill;
    int option;
    cout << "Please Enter your Choice: ";
    cin >> option;
    system("cls");

    if (option == 1)
    {
        category();
        product();
        customerInterface();
        customerChoice();
    }
    if (option == 2)
    {
        bill = customerOrder();
        cout << "YOUR TOTAL BILL IS...  RS. " << bill << endl;
        cout << endl;
        clearScreen();
        customerInterface();
        customerChoice();
    }
    if (option == 3)
    {
        paymentOption();
        cout << endl;
        clearScreen();
        customerInterface();
        customerChoice();
    }
   // else if (option == 4)
   // {
   //     header();
   //     int log = loginMenu();
  //}
}

void employeeChoice()
// this will take employee choice and will show according to his choice

{
    int choose;
    cout << "Please Enter your Choice: ";
    cin >> choose;
    
    
    if (choose == 1)
    {
        system("cls");
        checkOrder();   
        cout << endl;
        clearScreen();
        employeeInterface();
        employeeChoice();
    }
    if (choose == 2)
    {
        system("cls");
        viewOrders();
        cout << endl;
        clearScreen();
        employeeInterface();
        employeeChoice();
    }
   // if (choose == 3)
    //{
    //  header();
    // int log = loginMenu();
    //}
    clearScreen();
}

void category()
// this will show category list of products
{
    cout << endl;
    cout << "________________________"<< endl;
    cout << "|     CATEGORY LIST     |" << endl;
    cout << "-------------------------" << endl;
    cout << "1. Grocery" << endl;
    cout << "2. Crockery" << endl;
    cout << "3. Electronics" << endl;
    cout << "4. HomeDecor" << endl;
    cout << "5. Sports" << endl;
    cout << "6. Skincare/beauty products" << endl;
    cout << "7. Pharmaceuticals" << endl;
    cout << "8. Stationery" << endl;
    cout << "9. Back" << endl;
    cout << endl;
}

void addProduct()
// this function will be used to add new product by admin
{
    string pName;
    int pPrice;
    string productCategory;

     cout << endl << endl << endl;
    cout << "PROVIDE INFORMATION TO ADD NEW PRODUCT....." << endl << endl;
    cout << "Enter Product Category: ";
    cin >> productCategory;
    cout << "Enter Product Name: ";
    cin >> pName;
    cout << "Enter Price: ";
    cin >> pPrice;
    
    for (int i = 0; i < productCount; i++)
    {
        if (productCategory == categories[i])
        {
            if (productCount < size)
            {
                categories[productCount + 1] = productCategory;
                productName[productCount + 1] = pName;
                productPrice[productCount + 1] = pPrice;
                productCount++;
                cout << endl;
                storeProducts(productCategory, pName, pPrice);
                bool check = checkProductUpdate(pName);
                if (check == true)
                {
                    cout << "  > Product Added Successfully!" << endl;
                    break;
                }
                else 
                {
                    cout << "  > NEW PRODUCT NOT ADDED!! TRY AGAIN!!" << endl;
                    break;
            
                }
            }
        }
        else 
        {
            cout << "     > INVALID CATEGORY" << endl;
            break;
        }
    }
    clearScreen();
}

bool checkProductUpdate(string pName)
// this function is used to check if the product is added or not
{
    bool check = false;
    for (int i = 0; i < productCount; i++)
    {
        if (productName[i] == pName)
        {
            check = true;
            break;
        }

    }
}

void storeProducts(string productCategory, string pName, int pPrice)
// this function is used to store new products added in file
{
    fstream file;
    file.open("products.txt", ios::app);
    file << productCategory << "," << pName << "," << pPrice << endl;
    file.close();    
}

void loadProducts()
// this function is used to read product data from file and to load it
{
    fstream file;
    string record;
    file.open("products.txt", ios::in);
    while(getline(file, record))
    {
        categories[productCount + 1] = getParse(record, 1);
        productName[productCount +1] = getParse(record, 2);
        productPrice[productCount + 1] = stoi(getParse(record, 3));
        productCount++;
    }
    file.close();
}

void updateProductPrice()
// this function is will help admin to update price of particular product
{
    string pName;
    int newPrice;
    int oldPrice;

    cout << endl << endl << endl;
    cout << "PROVIDE INFORMATION TO UPDATE PRODUCT PRICE....." << endl << endl;
    cout << "Enter Product Name: ";
    cin >> pName;
    cout << "Enter Old price: ";
    cin >> oldPrice;
    cout << "Enter New Price: ";
    cin >> newPrice;
    for (int idx = 0; idx < productCount; idx++)
    {
        if (productName[idx] == pName && productPrice[idx] == oldPrice && newPrice > 0)
        {
            productPrice[idx] = newPrice;
        }
        else 
        {
            cout << "     > INVALID PRODUCT OR PRICE" << endl;
            break;
        }
    }
    cout << endl;
    bool check = checkProductPriceUpdate(pName, newPrice);
    if (check == true)
    {
        cout << "    > Product Price Updated" << endl;
    }
    else
    {
        cout << "    > PRICE NOT UPDATED!! TRY AGAIN!!" << endl;
    }
    clearScreen();
}

bool checkProductPriceUpdate(string pName, int newPrice)
// this function will check if the product price is updated or not
{
    bool check = false;
    for (int i = 0; i < productCount; i++)
    {
        if (productName[i] == pName && productPrice[i] == newPrice)
        {
            check = true;
            break;
        }
    }
    return check;
}

void deleteProduct()
// this will help user to delete a particular product
{
    string productCategory;
    string pName;
    string del =  " > DELETED";
    int del2 = 000; 

    cout << endl << endl << endl;
    cout << "PROVIDE INFORMATION TO DELETE PRODUCT....." << endl << endl;
    cout << "Enter Product Category: ";
    cin >> productCategory;
    cout << "Enter Product Name: ";
    cin >> pName;

    for (int idx = 0; idx < productCount; idx++)
    {
        if (categories[idx] == productCategory && productName[idx] == pName )
        {
            productName[idx] = del;
            productPrice[idx] = del2;
            break;
        }   
        else 
        {
            cout << "     > INVALID PRODUCT" << endl;
            break;
        }
    }
    cout << endl;

    bool check = checkProductDelete(productCategory, pName);
    if (check == true)
    {
        cout << " > Product Deleted Successfully!!" << endl;
    }
    else 
    {
        cout << " > PRODUCT NOT DELETED! TRY AGAIN!!" << endl;
    }
    clearScreen();
}

bool checkProductDelete(string pCategory, string pName)
// this will check if the product is deleted or not
{
    bool check = false;
    for (int i = 0; i < productCount; i++)
    {
        if (categories[i] != pCategory && productName[i] != pName)
        {
            check = true;
        }
    }
    return check;
}

int customerOrder()
// this will take order from customer and will return his total bill
{
    int amount, bill = 0;
    int num;
    int quantity;
    int prPrice;
    string prName;
    string pCategory;
    string customerName;
    string order;

    cout << "Enter Your UserName: ";
    cin >> customerName;
    cout << "How many Products You Want to buy: ";
    cin >> num;
    cout << endl;

    for (int i = 0; i < num; i++)
    {
        cout << " No. of Product: ";
        cin >> quantity;
        cout << "Product Category: ";
        cin >> pCategory;
        cout << "Product Name: ";
        cin >> prName;
        for (int i = 0; i < productCount; i++)
        {
            if (prName == productName[i])
            {
                prPrice = productPrice[i];
            }
        }
        order = order + prName + ";" ;
        amount = quantity * prPrice;
        bill = bill + amount;      // calculates total bill
    }

    addCustomerOrder(customerName, order, bill);
    storeOrders(customerName, order, bill);
    return bill;
}

void addCustomerOrder(string customerName, string order, int bill)
// this add customer order info to array
{
    customerUserNAmes[orderCount] = customerName;
    customerOrders[orderCount] = order;
    customerBills[orderCount] = bill;
    orderCount++;
}

void storeOrders(string customerName, string order, int bill)
// this will store customer order info to file
{
    fstream file;
    file.open("orders.txt" , ios::app);
    file << customerName << "," << order << "," << bill;
    file.close();
}

void loadOrderData()
// this will read order info from file and will load when the program executes
{
    fstream file;
    string record;
    file.open("orders.txt", ios::in);
    while(getline(file, record))
    {
        customerUserNAmes[orderCount] = getParse(record, 1);
        customerOrders[orderCount] = getParse(record, 2);
        customerBills[orderCount] = stoi(getParse(record, 3));
        orderCount++;
    }
    file.close();
}

void paymentOption()
// this asks customer to choose payment option
{
    string option;
    cout << endl << endl;
    cout << "Choose Payment Option (Card or Cash): ";
    cin >> option;
    cout << endl;
}

void product()
// this will show the list of products according to his choice
{
    int num;
    cout << "Enter your Choice: ";
    cin >> num;
    system("cls");
    
    cout << "    " << " PRODUCTS" << "\t\t" << "PRODUCT PRICES" << endl << endl << endl;
    if (num == 1)
    {
        for (int idx = 0; idx < size; idx++)
        {
            if (categories[idx] == "grocery")
                cout <<  "    " << ". " << productName[idx] << "\t\t" << "Rs. " << productPrice[idx] << endl;
        }
    }
    else if (num == 2)
    {
        for (int idx = 0; idx < size; idx++)
        {
            if (categories[idx] == "crockery")
                cout << "    " << ". " << productName[idx] << "\t\t" << "Rs. " << productPrice[idx] << endl;
        }
    }
    else if (num == 3)
    {
        for (int idx = 0; idx < size; idx++)
        {
            if (categories[idx] == "electronics")
                cout << "    " << ". " << productName[idx] << "\t\t" << "Rs. " << productPrice[idx] << endl;
        }
    }
    else if (num == 4)
    {
        for (int idx = 0; idx < size; idx++)
        {
            if (categories[idx] == "homeDecor")
                cout << "    " << ". " << productName[idx] << "\t\t" << "Rs. " << productPrice[idx] << endl;
        }
    }
    else if (num == 5)
    {
        for (int idx = 0; idx < size; idx++)
        {
            if (categories[idx] == "sports")
                cout << "    " << ". " << productName[idx] << "\t\t" << "Rs. " << productPrice[idx] << endl;
        }
    }
    else if (num == 6)
    {
        for (int idx = 0; idx < size; idx++)
        {
            if (categories[idx] == "skincareOrBeautyProducts")
                cout << "    " << ". " << productName[idx] << "\t\t" << "Rs. " << productPrice[idx] << endl;
        }
    }
    else if (num == 7)
    {
        for (int idx = 0; idx < size; idx++)
        {
            if (categories[idx] == "pharmaceuticals")
                cout << "    " << ". " << productName[idx] << "\t\t" << "Rs. " << productPrice[idx] << endl;
        }
    }
    else if (num == 8)
    {
        for (int idx = 0; idx < size; idx++)
        {
            if (categories[idx] == "stationery")
                cout << "    " << ". " << productName[idx] << "\t\t" << "Rs. " << productPrice[idx] << endl;
        }
    }
    else if (num == 9 && flag == true)
    {
        clearScreen();
        customerInterface();
        customerChoice();
    }
    else if (num == 9 && flag == false)
    {
        clearScreen();
        adminInterface();
        adminChoice();
    }

    clearScreen();
}

void checkOrder()
{
    cout << endl << endl << endl;
    if (orderCount == 0)
    {
        cout << " > NO ORDERS YET!!" << endl;
    }
    else if (orderCount != 0)
    {
        cout << "> Check Customer Detail...." << endl;
    }
}

void viewOrders()
// this will help user to view complete info of orders made by customers
{
    cout << endl << endl;
    cout << "CUSTOMER NAMES " << "\t" << "CUSTOMER ORDERS " << "\t" << "CUSTOMER BILLS " << endl;
    cout << endl << endl;
    for (int i = 0; i < orderCount; i++)
    {
        cout << customerUserNAmes[i] << "\t" << customerOrders[i] << "\t" << customerBills[i] << endl;
    }
}