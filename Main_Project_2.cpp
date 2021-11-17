#include "get_entity.h"
#include "get_states.h"
#include "State.h"
#include "Next_State.h"
#include "Output_Logic.h"

int main()
{
    string FileName = "Moore_design.sv";
    string SpecTable = "State_Table_3.txt";
    array <map <string, array <int, 2>>, 2> Entity;
    array <map <string, vector <string>>, 2> States;

    Entity = get_entity(SpecTable);
    States = get_states(SpecTable);

    State(FileName, Entity, States);
    NextState(FileName, Entity, States);
    OutputLogic(FileName, Entity, States);

    return 0;
}