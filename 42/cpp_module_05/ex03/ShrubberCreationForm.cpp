#include "ShrubberCreationForm.hpp"
#include "Form.hpp"

// Constructors
ShrubberCreationForm::ShrubberCreationForm() : Form("ShrubberCreation", 145, 137)
{
	this->_target = "no target";
	std::cout << "\e[0;33mDefault Constructor called of ShrubberCreationForm\e[0m" << std::endl;
}

ShrubberCreationForm::ShrubberCreationForm(std::string name) : Form("ShrubberCreation", 145, 137)
{
	this->_target = name;
	std::cout << "\e[0;33mDefault Constructor called of ShrubberCreationForm\e[0m" << std::endl;
}

ShrubberCreationForm::ShrubberCreationForm(const ShrubberCreationForm &copy) : Form("ShrubberCreation", 145, 137)
{
	this->_target = copy._target;
	std::cout << "\e[0;33mCopy Constructor called of ShrubberCreationForm\e[0m" << std::endl;
}

// Destructor
ShrubberCreationForm::~ShrubberCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberCreationForm\e[0m" << std::endl;
}

// Operators
ShrubberCreationForm & ShrubberCreationForm::operator=(const ShrubberCreationForm &assign)
{
	this->_target = assign._target;
	return *this;
}

void	ShrubberCreationForm::procedure() const
{
	std::string fileName;
	std::ofstream file;

	fileName = this->_target;
	fileName.append("_shrubbery");
	file.open(fileName);
	if (!file.is_open())
	{
		std::cout << "Error opening " << fileName << std::endl;
		return ;
	}
	file << "|··················································|" << std::endl;
	file << "|······················)Dp·························|" << std::endl;
	file << "|············c··············pq·····················|" << std::endl;
	file << "|··········DDp··)Dp····p··dDDC····dG··(DD··········|" << std::endl;
	file << "|···········(()··)D····DD········DD··c(············|" << std::endl;
	file << "|··················Pq···SC·····sec·················|" << std::endl;
	file << "|············sp·····q(s······))p·····pp············|" << std::endl;
	file << "|·····)DDqp···)Db··SPC·b····)·)PD··)DD···pqDDC·····|" << std::endl;
	file << "|···············c((·u···p·p·G··e·ccbc··············|" << std::endl;
	file << "|········sqqpc·ee(PDDpb·)··)·dqDDPSeeocqqqp········|" << std::endl;
	file << "|·······((P·c··)DC·)···))pDCP···dc)Dp····SPC·······|" << std::endl;
	file << "|··············Oc···(Q··DDDp··)C····S··············|" << std::endl;
	file << "|········sd···········b·)DDC·d···········bp········|" << std::endl;
	file << "|·······)DC············b·DDG)·············DC·······|" << std::endl;
	file << "|·······················DDDpG······················|" << std::endl;
	file << "|·······················DDDD·······················|" << std::endl;
	file << "|·······················)DDD·······················|" << std::endl;
	file << "|·······················)DDD·······················|" << std::endl;
	file << "|·······················DDDD·······················|" << std::endl;
	file << "|·······················DDDDp······················|" << std::endl;
	file << "|······················dDDDDD······················|" << std::endl;
	file.close();
}