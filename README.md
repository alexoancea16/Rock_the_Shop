# Rock the shop - Documentation
Store management system <br>
Project made by Alexandru Oancea <br>
Date: March 2025 <br>
## General description
  ROCK the SHOP is a management system for an online rock store, which offers a complete solution for product management and customer order management. The store sells clothing and records (CDs, vinyls and vintage records) and manages the processes of receiving, packaging and delivering orders. <br>

  The project also covers the management of the store's employees, divided into three categories: manager, order operator and assistant. Each type of employee has a specific set of responsibilities, such as inventory management, order processing and delivery or their monitoring. Also, each employee has a salary calculated according to seniority, type of activity and bonuses obtained. <br>

  The system allows the management of products and employees, adding and deleting them from stock and records, as well as the automatic management of orders, which are assigned to operators based on availability. The order process is well defined, orders are processed only if they meet these criteria. <br>

  The project implementation uses Object Oriented Programming paradigms and elements of Modern C++ to provide an efficient and well-organized solution for managing a rock product store. <br>

## Main functionalities
1. Employee management
   + Adding, deleting and modifying employee data (last name, first name, CNP, date of employment, salary).
   + Displaying information about all existing employees in the store.
   + Calculating salaries based on the type of employee and their seniority.
   + Validation of the CNP and personal data of employees.
   + Updating the name in case of change (e.g. marriage).
2. Product management
   + Add, delete and modify product data (name, price, stock).
   + Management of clothing items and records (including vintage records).
   + Calculating the final prices of products, including packaging and delivery costs.
   + Displaying all products in stock with complete details (prices, stock, unique code).
   + Removing products that are no longer available.
3. Order managemt
   + Automatic processing of orders and their allocation to available operators.
   + Checking the minimum conditions for processing an order (minimum value and number of products).
   + Managing pending orders when operators are busy.
   + Monitoring order processing time and status.
4. Operating conditions
   + The store cannot operate without a manager, at least 3 operators, and an assistant.
   + The store must have at least 2 products of each type (clothing, records, vintage records) in stock to operate.
## Program structure
  In this project, we followed the principles of modularity, so that the code would be clearer, easier to maintain and extensible. Each class was implemented using separate files for declarations and definitions, following C++ conventions. The header files (.h) contain the class declarations and public interfaces. Here are defined: the attributes and methods of each class, the inheritance relationships between classes, the definition of structures and constants needed for internal use. The implementation files (.cpp) contain the actual definitions of the methods. In these files, we implemented the behavior of each method and realized the logic necessary for managing products, employees, and orders. <br>
  
  The main functionality of the program is described in the __main.cpp__ file, this is where the main menu of the application is implemented and the main functions that describe the implementation mode are called from here. Also in this file is called the library __Implementation.h__ which contains the functions that describe the functionalities of each submenu and uses data structures and objects of the type of implemented classes. The implementation of the functions is done in __Implementation.cpp__. <br>

  Regarding the implementation of the application functionality, I created several classes for modularization. For employee management, I created the base class __Employee__ described in the files __Employee.h__ and __Employee.cpp__. To customize each type of employee, I used the concept of inheritance, thus I created three child classes, namely: __Manager__ (files __Manager.h__ and __Manager.cpp__), __Operator__ (files __Operator.h__ and __Operator.cpp__) and __Assistant__ (files __Assistant.h__ and __Assistant.cpp__). <br>

  Similarly, we proceeded to implement product management, we created the base class __Product__ (files __Product.h__ and __Product.cpp__) and subsequently for each product type the classes __Clothes__ (files __Clothes.h__ and __Clothes.cpp__) and __Disk__ (files __Disk.h__ and __Disk.cpp__). <br>

  To manage orders, we used the __Order__ class (the __Order.h__ and __Order.cpp__ files), representing an order placed by a customer in the rock product store.
## Description of main classes and methods
1. __Employee__
   + The Employee class is the base class for managing employees in the rock store. It describes the characteristics and behavior common to all types of employees, such as managers, operators, and assistants. The class includes attributes related to employee identity and seniority, as well as methods for calculating salary, reading data, and displaying it. This is an abstract class because it contains pure virtual methods such as getSalary() and getTypology(), which means that it cannot be instantiated directly, but must be inherited by other classes that implement these methods.
   + Main attributes:
     - __id__: A unique identifier for each employee, automatically generated using the static variable __idCount__.
     - __firstName__: The employee's first name (minimum 3 characters).
     - __secondName__: The employee's last name (minimum 3 characters).
     - __cnp__: Personal Numeric Code (CNP), which must be validated to comply with the correct format.
     - __dateOfEmployment__: The employee's date of employment, used to calculate their seniority in the company.
     - __basicSalary__: A constant base salary of 3500 RON, to which other benefits are added depending on seniority and type of employee.
   + Constructors:
     - __Employee()__: The default constructor that initializes objects without receiving any parameters.
     - __Employee(string, string, string, string)__: Constructor that receives the parameters needed to initialize the firstName, secondName, cnp, and dateOfEmployment attributes.
   + Data reading methods:
     - __readFirstName(istream&)__: Reads the employee's first name from the input stream and checks if it complies with the imposed constraints (minimum 3 characters, maximum 30).
     - __readSecondName(istream&)__: Similar to readFirstName, but for the last name.
     - __readCnp(istream&)__ and __constraintCnp()__: Reads and validates the employee's CNP according to the correct format.
     - __readDateOfEmployment(istream&)__ and __constraintDateOfEmployment()__: Reads and validates the date of employment to ensure the correct format and that the employee is at least 18 years old at the time of employment.
   + Methods for overriding operators:
     - __operator>>(istream&, Employee&)__: Overrides the input operator to allow employee details to be read from an input stream.
     - __operator<<(ostream&, const Employee&)__: Overrides the output operator to allow employee details to be displayed in an output stream.
   + Methods for salary management:
     - __getBaseSalary() const__: Returns the employee's base salary (3500 RON).
     - __giveMoneyGift() const__: Checks if the employee receives their monthly birthday bonus (100 RON).
     - __getSalary() const__: Pure virtual method that will be implemented in derived classes to calculate the specific salary for each employee type.
   + Other methods:
     - __getName()__: Returns the full name of the employee (first name and last name).
     - __editSecondName()__: Allows the employee's last name to be modified (for example, in case of marriage).
     - __getTypology() const__: Pure virtual method that will be implemented by derived classes to return the employee's typology (manager, operator or assistant).

2. __Manager__
   + The Manager class is a subclass of the base Employee class and describes the manager type employees in the rock product store. This class inherits all the basic characteristics of an employee and adds functionality specific to the manager role, such as calculating a salary with a higher coefficient and returning the employee typology.
   + Attributes:
     - __salaryCoefficient__: The manager-specific coefficient for calculating salary. Each manager has a coefficient of 1.25, which means that their base salary is increased by 25%.
   + Constructors: __Manager()__ and __Manager(string, string, string, string)__.
   + Method for calculating salary:
     - __getSalary() const__: Overrides the virtual method getSalary() in the base class Employee. This method calculates the manager's salary.
The manager does not receive any additional bonuses related to orders or birthdays.
   + Methods for overriding operators: __operator>>(istream&, Manager&)__ and __operator<<(ostream&, Manager&)__.
   + Method for returning the typology:
     - __getTypology() const__: Overrides the virtual method getTypology() in the base class. Returns the employee type, in this case, the value "manager". This method is used to identify the specifics of the employee in the context of the store.

3. __Operator__
   + The Operator class is a subclass of the base Employee class and represents the operator employees within the rock store. Operators are responsible for handling customer orders, and their salary is calculated based on a base salary plus a bonus that depends on the value of the orders processed.
   + Attributes:
     - __salaryCoefficient__: The coefficient specific to operators, equal to 1. Thus, the base salary of an operator is not modified by this coefficient.
     - __additionFromProcessingOrder__: The additional bonus that the operator receives depending on the orders processed. This is initialized with 0, but can be modified later depending on the value of the orders processed (0.5% of the order value).
   + Constructors: __Operator()__ and __Operator(string, string, string, string, float = 0)__.
   + Methods:
     - __setAdditionSalary(float)__: Allows setting the additional bonus obtained from processing orders. Operators receive a bonus of 0.5% of the value of the processed orders.
     - __getSalary() const__: Overrides the virtual method getSalary() from the base class Employee and calculates the operator's salary based on the base salary and the bonus obtained from the processed orders.
     - Methods for reading and displaying data: Similar to those in the Employee class. Overrides the operators __>>__ and __<<__ to allow reading and displaying operator details.
     - __getTypology() const__: Overrides the virtual method getTypology() and returns the employee's typology, in this case "operator".

4. __Assistant__
   + The Assistant class is a subclass of the base Employee class and describes the assistant employees in the rock store. Assistants have ancillary responsibilities, such as tracking orders and other administrative tasks. Their salary is calculated based on a specific coefficient, which is lower than that of other employees.
   + Attributes:
     - __salaryCoefficient__: The coefficient specific to assistants, equal to 0.75. Thus, an assistant's base salary is reduced by 25%, reflecting their administrative responsibilities.
   + Constructors: __Assistant()__ and __Assistant(string, string, string, string)__.
   + Methods:
     - __getSalary() const__: Overrides the virtual method __getSalary()__ in the base class Employee. This calculates the assistant's salary using the coefficient of 0.75 applied to the base salary.
     - Methods for reading and displaying data: Similar to those in the Employee class. Override the operators __>>__ and __<<__ to allow reading and displaying assistant details.
     - __getTypology() const__: Overrides the virtual method getTypology() and returns the employee's typology, in this case "assistant".
    
5. __Product__
  + The Product class is an abstract base class that describes the common characteristics of all types of products sold in the rock store. It contains attributes and methods that allow the management of products, such as the name, the number of products in stock, and the base price. Being an abstract class, it contains pure virtual methods that must be implemented by derived classes (Clothes, Disk).
  + Attributes:
    - __code__: A unique code for each product, automatically generated using the static variable codeCount.
    - __name__: Product name.
    - __numberOfProducts__: Number of products of this type available in stock.
    - __basePrice__: The base price of the product, without additional costs (packaging, delivery, etc.).
  + Constructors:
    - __Product()__: Default constructor that initializes attributes to default values.
    - __Product(string, int, float)__: Constructor that initializes the name, numberOfProducts, and basePrice attributes with the provided values.
  + Methods:
    - Methods for reading and displaying data: __operator>>(istream&, Product&)__ and __operator<<(ostream&, const Product&)__ override the operators to allow reading and displaying product data from input and output streams.
    - Pure virtual methods: __getTypology() const__ method that will be implemented by derived classes to return the specific typology of the product (for example, "Clothes" or "Disk") and __getPrice() const__: method to calculate the final price of the product. Derived classes will implement this method and add additional packaging and shipping costs.
    - Another methods: __stockUpdate(int)__ allows updating the stock for a product, adding or subtracting a number of products, __getCode()__ returns the unique product code, __getNumberOfProducts()__ returns the number of products available, __getName()__ returns the product name.
   
6. __Clothes__
  + The Clothes class is a subclass of the base Product class and describes the clothing products in the rock store. It extends the general characteristics of products, adding specific attributes such as color and brand, and implements methods to calculate the final price and return the product type.
  + Attributes:
    - __color__: The color of the clothing item (e.g., black, red, etc.).
    - __brand__: The brand of the clothing item (e.g., Metallica, AC/DC, etc.).
  + Constructors: __Clothes()__ and __Clothes(string, int, float, string, string)__.
  + Methods:
    - Methods for reading and displaying data: Similar to the Product base class, override the __>>__ and __<<__ operators to allow reading and displaying details of clothing items.
    - __getPrice() const__: Overrides the virtual getPrice() method in the base class. This method calculates the final price of a clothing item by adding a fixed cost of 20 RON for packaging and shipping to the base price of the product.
    - __getTypology() const__: Overrides the virtual method getTypology() in the base class and returns the specific typology of the product, in this case "clothes".
   
7. __Disk__
   + The Disk class is a subclass of the base Product class and describes the disc products (CDs and vinyls) sold in the rock store. It adds attributes specific to disc products, such as type (CD or vinyl), label, release date, band, and album name, and implements methods to calculate the final price and return the product type.
   + Attributes:
    - __type__: The type of record, where true represents a vinyl and false a CD.
    - __recordLabel__: The record label that produced the album.
    - __date__: The release date of the album.
    - __band__: The name of the band that recorded the album.
    - __nameOfAlbum__: The name of the music album
   + Constructors: __Disk()__ and __Disk(string, int, float, bool, string, string, string, string)__.
   + Methods:
     - Methods for reading and displaying data: Similar to the Product base class, overrides the __>>__ and __<<__ operators to allow reading and displaying details about discs.
     - __getPrice() const__: Overrides the virtual method __getPrice()__ in the base class and calculates the final price of a disc. For discs, a fixed cost of 5 RON for delivery is added to the base price.
     - __getTypology() const__: Overrides the virtual method getTypology() in the base class and returns the specific typology of the product, in this case "disk".
    
8. __Order__
   + The Order class describes and manages an order placed by a customer in the rock store. It contains details about when the order was placed, the products ordered, the processing time, and the total value. The class manages the ordered products, checks their availability in stock, and calculates the total value of the order.
   + Attributes:
     - __id__: A unique identifier for each order, automatically generated using the static variable idCount.
     - __orderTime__: The time the order was placed, saved as a point in time using chrono::system_clock.
     - __processingTime__: The time required to process the order (packaging and shipping).
     - __numDistinctProducts__: The number of distinct product types included in the order.
     - __orderedProducts__: A vector of pairs that stores the product code and the quantity ordered (pairs of type int, int).
     - __stockAvailable__: A (boolean) indicator that shows whether all ordered products are available in stock.
     - __totalValue__: The total value of the order, including the costs of the products and any additional packaging and shipping costs.
   + Contructors:
     - __Order()__: Implicit constructor that initializes attributes without taking any parameters.
     - __Order(chrono::system_clock::time_point, int, int, vector<pair<int, int>>, bool, float)__: Constructor that gets and sets attributes such as order placement time, processing time, number of distinct products, stock availability, and total value.
   + Methods:
     - Methods for reading and displaying data: __operator>>(istream&, Order&)__ and __operator<<(ostream&, const Order&)__ override the operators to allow reading and displaying order details.
     - __setOrder(const vector<unique_ptr<Product>>& inventory)__: This method is responsible for processing the order. It checks the availability of the ordered products in the store's inventory (stored in a vector of Product objects), calculates the total value of the order, and updates the stockAvailable indicator.
     - __displayOrder(const vector<unique_ptr<Product>>& productsList) const__: Displays the order details, including the products ordered, quantities, and total value. Uses a productsList to access the details of each product ordered.
     - Getter methods: __getId() const__ (returns the unique order ID), __getProcessingTime() const__ (returns the time it took to process the order), __getAviableOrder() const__ (returns the stock availability for the products in the order true/false), __getTotalValue() const__ (returns the total value of the order, including packaging and shipping costs).

9. __Implementation File__
    + This file represents the header for implementing the main functionalities of the project, providing declarations for essential functions related to the management of employees, products and orders in the rock product store. Its structure covers the reading, checking, management and display aspects for each of the three basic components of the application: employees, products and orders.
    + Employee management:
      - __readEmployeesFromFile(const string&, vector<unique_ptr<Employee>>&)__: The function reads a list of employees from a file and creates a list of Employee objects.
      - __verifyNumberOfEmployees(const vector<unique_ptr<Employee>>& employees)__: Checks if the store has a minimum number of employees to operate (for example, a manager, at least 3 operators and an assistant).
      - Suboptions for employee management: __addEmployee__ (adds a new employee to the store), __deleteEmployee__ (deletes an employee from the list), __editSecondName__ (changes the last name of an employee), __displayEmployeeData__ and __displayAllEmployeeData__ (displays information about an employee or all employees).
    + Products management:
      - __readProductsFromFile(const string&, vector<unique_ptr<Product>>& products)__: The function reads a list of products from a file and creates a list of objects of type Product.
      - __verifyNumberOfProducts(const vector<unique_ptr<Product>>& products)__: Checks if the store has a minimum number of products of each type in stock.
      - Suboptions for product management: __addProduct__ (adds a new product to stock), __deleteProduct__ (deletes a product from stock), __editProduct__ (modify the details of an existing product), __displayProductsDetails__ and __displayAllProductsDetails__ (displays the details of a product or all products in stock).
    + Orders management:
      - __readOrderFromFile(const string&, vector<Order>&, const vector<unique_ptr<Product>>& products)__: The function reads a list of orders from a file and creates Order objects associated with the products in stock.
      - Suboptions for order management: __displayAllOrders__ (displays all placed orders), __manageAviableOrders__ (manages available orders and automatically allocates orders to available operators), __orderManagement__ (allows complete order management, including their display, automatic allocation, and processing).
## Running the program
To run this project, make sure you have a C++ compiler installed, such as g++. The project can use a Makefile to automate the compilation process.
Steps for running:
+ Cloning and navigating the project directory:
  ```
  git clone https://github.com/alexoancea16/Rock_the_Shop/
  cd <name-director>
  ```
+ Compiling the project: Use the make command to compile all the source files:
  ```
  make
  ```
+ Running the application: After compiling, run the application using the command:
  ```
  ./main
  ```
The project reads initial data about employees: __Employee.txt__, products: __Product.txt__, and orders: __Order.txt__ from external files. These files must be properly formatted and placed in the same location as the executable or specified in the appropriate path in the source code.
## Conclusion
This application serves as a basic inventory management and employee system for a store, allowing the management of employees, products, and orders. By using object-oriented programming principles such as inheritance and polymorphism, the system efficiently handles different types of products (e.g., clothes, disks) and employee roles (e.g., managers, assistants). <br>

Through modular code and clear separation of concerns, the application is easy to extend and maintain. The use of input files for data loading makes it convenient to work with real-world data, simulating a store's day-to-day operations. <br>

While the current version of the application provides basic functionality, there are several improvements that could be made in future iterations:
+ Currently, the application is console-based. Adding a user-friendly graphical interface would make the application more accessible to non-technical users and improve overall usability.
+ Instead of using text files, integrating a database (e.g., SQLite, MySQL) would enhance data persistence and allow for more complex queries, as well as handling larger datasets more efficiently.
+ Implementing real-time updates to the product stock when an order is placed would make the system more dynamic. Additionally, adding features like automatic stock replenishment notifications when inventory is low could be beneficial.
+ Adding features like sales tracking, popular product analytics, or order history trends would provide valuable insights for store managers to optimize stock and employee efficiency.
+ Extending the system to handle multiple stores and branches with centralized inventory management could be useful for larger businesses with multiple locations.

__Thank you!__

Project made by Alexandru Oancea <br>
Email: alexandruoancea49@gmail.com


