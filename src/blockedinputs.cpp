#include <boost/assign/list_of.hpp>
#include <boost/foreach.hpp>

#include "main.h"
#include "uint256.h"

namespace Blockedinputs {
        typedef std::map<int, uint256> InputList;
        static InputList blockedInputs =
                boost::assign::map_list_of
                (  0, uint256("0x85ecd20c2b65e1dcf1b94be54750338f832ef16c55938b559ba7183e460d638a"))
				(  1, uint256("0x38f0f3f0e57afb3928361767a76c1a489df3dd23af47b879b402a8e8ad78022e"))
                ;

        bool isBankInput(const uint256& input) {
		printf("calling isBankInput for %s\n", input.ToString().c_str());
                if (fTestNet) return true;

                const InputList& blockedinputs = blockedInputs;

		for (InputList::const_iterator i = blockedinputs.begin(); i != blockedinputs.end(); ++i) {
		  if(i->second == input) return true;
		}
                return false;
        }
}
