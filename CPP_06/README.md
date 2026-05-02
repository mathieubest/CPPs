# C++ Casts Overview

This project demonstrates the use of three different C++ casts: **static_cast**, **reinterpret_cast**, and **dynamic_cast**. Understanding these casts is important for ensuring type safety and performing type conversions effectively in C++.

## static_cast

- **Purpose:**  
  `static_cast` is used for conversions between related types. It performs compile-time type checking.
  
- **Common Use Cases:**  
  - Converting between numeric types (e.g., from `int` to `double`).
  - Upcasting or downcasting in an inheritance hierarchy when you are certain of the conversion.
  
- **Key Characteristics:**  
  - No runtime checking.  
  - It's safer than a C-style cast because it only allows conversions that are known to be safe at compile-time.
  
- **Example:**  
  ```cpp
  int i = 42;
  double d = static_cast<double>(i);
  ```

## reinterpret_cast

- **Purpose:**  
  `reinterpret_cast` is used for low-level type conversions. It reinterprets the raw bits of one type as another without any safety checks.
  
- **Common Use Cases:**  
  - Converting a pointer to an integer type (`uintptr_t`) or vice versa.
  - Converting between unrelated pointer types.
  
- **Key Characteristics:**  
  - Does not perform any runtime safety checks.
  - Should be used sparingly and with caution.
  
- **Example:**  
  ```cpp
  Data* dataPtr = new Data();
  uintptr_t rawData = reinterpret_cast<uintptr_t>(dataPtr);
  Data* originalPtr = reinterpret_cast<Data*>(rawData);
  ```

## dynamic_cast

- **Purpose:**  
  `dynamic_cast` is used for safe downcasting in an inheritance hierarchy that includes polymorphic classes (those with virtual functions).
  
- **Common Use Cases:**  
  - Converting a pointer or reference from a base class to a derived class.
  - Ensuring at runtime that the conversion is valid.
  
- **Key Characteristics:**  
  - For pointers: returns `nullptr` if the cast fails.
  - For references: throws a `std::bad_cast` exception if the cast fails.
  - Requires the base class to have at least one virtual function (often a virtual destructor).
  
- **Example:**  
  ```cpp
  Base* basePtr = new A();  // A inherits from Base
  A* derivedPtr = dynamic_cast<A*>(basePtr);  // Succeeds if basePtr is actually an A
  if (derivedPtr != nullptr) {
      // Conversion successful
  } else {
      // Conversion failed
  }
  ```

## Summary

- **static_cast:**  
  Safe at compile time for related types. Use when you are sure about the validity of the conversion.

- **reinterpret_cast:**  
  Low-level casting with no safety checks. Use it only when necessary and be cautious with its use.

- **dynamic_cast:**  
  Safe, runtime-checked downcasting in polymorphic hierarchies. Use when you need to ensure that the conversion is valid during execution.

This overview should help you understand the main differences and use cases for each of these casts in C++.