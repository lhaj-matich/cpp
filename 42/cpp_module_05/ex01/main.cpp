#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
  
  {
      Bureaucrat chrif("Chrif", 75);
      Form Sokna("Chahada sokna", 80, 90);

      chrif.signForm(Sokna);
  }
  {
      Bureaucrat chrif("Ostad", 75);
      Form Sokna("Chahada work", 70, 90);

      chrif.signForm(Sokna);
  }
   return (0);
}
