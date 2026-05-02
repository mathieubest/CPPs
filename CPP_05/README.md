# Exception Handling Across the CPP_05 Exercises

This document explains how exceptions are integrated and used differently across the various exercises of the CPP_05 project.

## Exercise 0 – Basic Bureaucrat

- **Focus:**  
  Exercise 0 focuses on the basic functionality of the Bureaucrat class.  
- **Exception Handling:**  
  - The `Bureaucrat` class throws custom exceptions (`GradeTooHighException` and `GradeTooLowException`) when trying to create or modify a bureaucrat's grade out of the valid range (1 to 150).
  - These exceptions are used to prevent invalid construction or state change, as seen in methods like `setGrade`, `incrementGrade`, and `decrementGrade`.

## Exercise 1 – Forms with Basic Exception Rules

- **Focus:**  
  Exercise 1 introduces a `Form` class (similar to `AForm` in later exercises) that a Bureaucrat can sign.
- **Exception Handling:**  
  - The `Form` constructor validates its grade requirements and, similar to Bureaucrat, throws `GradeTooHighException` or `GradeTooLowException` when the constructor parameters are out of bounds.
  - The signing functionality utilizes these exceptions by verifying if a Bureaucrat’s grade is high enough to sign. If not, the Bureaucrat’s `signForm` method catches the exception and reports the issue.

## Exercise 2 – AForm and Derived Forms

- **Focus:**  
  Exercise 2 expands on the concepts by introducing an abstract `AForm` class along with several derived forms (e.g., ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm).
- **Exception Handling:**  
  - **AForm Validation:**  
    The `AForm` constructor validates the signing and execution grade limits. It throws custom exceptions if either limit is not in the range.
  - **Form Operations:**  
    - When a Bureaucrat attempts to sign a form, the `beSigned` method either updates the form’s signature status or throws a `GradeTooLowException` if the Bureaucrat’s grade is insufficient.
    - When executing a form, if the form is not signed the `execute` method throws a `std::runtime_error`, and if a Bureaucrat’s grade is too low for execution, a `GradeTooLowException` is thrown.
  - **Target Validation:**  
    For forms that act on a target (for example, creating a file or performing an action on a named entity), the method `checkTarget` ensures the target is not empty. A missing target leads to a `std::invalid_argument` exception.

## Exercise 3 – Intern and Dynamic Form Creation

- **Focus:**  
  Exercise 3 introduces an `Intern` class, which is responsible for creating different types of forms on demand.
- **Exception Handling:**  
  - The `Intern::makeForm` method uses a loop to match a requested form name against a list of known forms.
  - If the form name is not found, the method throws a custom `FormNotFoundException` to indicate the error.
  - The handling of incorrect form names through exceptions helps prevent the creation of undefined forms and makes the error message explicit.
  - Additionally, forms created (which are of types defined in Exercise 2) continue to enforce their internal validations as described above.

## Summary

Each exercise builds on the previous one:
- **Exercise 0** lays the foundation with basic grade checks in the Bureaucrat.
- **Exercise 1** integrates signing forms with similar grade checks.
- **Exercise 2** introduces a hierarchy of forms with richer behaviors and target validation.
- **Exercise 3** adds dynamic form creation via an Intern, demonstrating how exceptions can also manage invalid user requests.

Understanding these patterns is essential for managing error conditions gracefully and maintaining robust C++ applications.

## Best Practices Illustrated

- **Early Validation:**  
  The code checks for invalid input or state at the earliest possible point (e.g., during grade setting or form creation), allowing the program to handle errors gracefully.

- **Clear Error Messages:**  
  Custom exceptions deliver descriptive error messages (sometimes enhanced with color codes) that not only tell you that something went wrong but also provide hints about how to fix or avoid the problem.

- **Separation of Concerns:**  
  By separating error detection (throwing exceptions) from error resolution (catching exceptions and performing cleanup), the project maintains cleaner and more maintainable code.

## Conclusion

Exception handling is a core part of building robust C++ applications. In the CPP_05 project, you can see how both standard and custom exceptions work together to enforce valid operation and provide clear feedback when things go wrong. Understanding these patterns is key to effective error management in C++.
