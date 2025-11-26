# Проект: Библиотека (Library System)

## Описание

Проектът **„Библиотека“** представлява малка C++ система, която моделира работа с книги, автори, читатели и заеми чрез няколко взаимосвързани класа — `Author`, `Book`, `Member`, `Loan` и `Library`.  
Той демонстрира прилагането на основни обектно-ориентирани концепции в C++:

- конструктори, копиране и преместване (Rule of 3/5);
- капсулация и достъп чрез getters и setters;
- `const`-коректност и валидация на данни;
- статични членове и методи;
- управление на обекти чрез STL контейнери;
- добри ООП практики в реалистична система.

---

## Структура на проекта

library/                                                                                                                                                       
├── Author.h                                                                                                                                                        
├── Book.h                                                                                                                                                       
├── Member.h                                                                                                                                                       
├── Loan.h                                                                                                                                                         
├── Library.h                                                                                                                                                       
├── Library.cpp                                                                                                                                                     
├── README.md                                                                                                                                                       
├── image.png                                                                                                                                                       
└── main.cpp                                                                                                                                                       


---

## Изпълнение в CodeBlocks

1. Отворете **CodeBlocks**
2. File → New → Project → *Console Application*
3. Добавете всички `.h` и `.cpp` файлове към проекта
4. Натиснете **Build & Run**

---

## Примерен изход

Library summary:                                                                                                                                                    
Books: 2                                                                                                                                                       
Members: 1                                                                                                                                                       
Active loans: 0                                                                                                                                                     
Loan created.                                                                                                                                                       
Available ISBN-001? false                                                                                                                                           
Available ISBN-001? true                                                                                                                                            


---

## Класове

### Клас `Author`

Представя автор с базова информация.

**Членове:**
- `std::string name` — име  
- `int birthYear` — година на раждане  

**Методи:**
- конструктори (по подразбиране и параметризиран)  
- `setBirthYear(int)` с валидиране  
- `getName() const`  
- `to_string() const`  

---

### Клас `Book`

Представя книга с автор и основни характеристики.

**Членове:**
- `std::string title`  
- `Author author`  
- `int year`  
- `double price`  
- `std::string isbn`  
- `static int totalBooks` — брой живи книги  

**Методи:**
- конструктори (по подразбиране и параметризиран)  
- копиращ и преместващ конструктор (`Rule of 5`)  
- копиращ и преместващ оператор (`= default`)  
- деструктор (`= default`)  
- валидиране на година и цена  
- `to_string() const`  
- `static int getTotalBooks()`  

---

### Клас `Member`

Представя регистриран читател.

**Членове:**
- `std::string name`  
- `std::string memberId`  
- `int yearJoined`  

**Методи:**
- конструктори (по подразбиране и параметризиран)  
- валидиране на memberId  
- `to_string() const`  

---

### Клас `Loan`

Представя заемане на книга от читател.

**Членове:**
- `std::string isbn`  
- `std::string memberId`  
- `std::string startDate`  
- `std::string dueDate`  
- `bool returned`  

**Методи:**
- конструктор (валидира, че dueDate ≥ startDate)  
- `markReturned()`  
- `isOverdue(const std::string& today) const` — лексикографска проверка YYYY-MM-DD  
- `to_string() const`  

---

### Клас `Library`

Централен клас, който управлява всички книги, членове и заеми.

**Членове:**
- `std::vector<Book> books`  
- `std::vector<Member> members`  
- `std::vector<Loan> loans`  

**Методи:**
- `addBook(const Book&)`  
- `addMember(const Member&)`  
- `hasBook(const std::string& isbn) const`  
- `isBookAvailable(const std::string& isbn) const`  
- `loanBook(const std::string& isbn, const std::string& memberId, const std::string& start, const std::string& due)`  
- `returnBook(const std::string& isbn, const std::string& memberId)`  
- `findByAuthor(const std::string& authorName) const`  
- `to_string() const`  

---

## Образователни цели

Проектът има за цел да демонстрира:

- разделение между интерфейс (`.h`) и имплементация (`.cpp`);
- използване на списъци за инициализация;
- правилно управление на копиране и преместване (Rule of 3/5);
- работа с колекции (std::vector) и статични членове;
- константна коректност и валидиране на данни;
- добри обектно-ориентирани практики.

---

## Екранна снимка

![screenshot](/image.png)

---

## Автор

**Име:** Благой Татарски
**Номер:** 22303
**Курс:** Обектно-ориентирано програмиране (C++)  
**Дата:** 26.11.2025г.
