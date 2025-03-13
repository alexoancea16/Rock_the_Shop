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
## Running the program
## Conclusion
