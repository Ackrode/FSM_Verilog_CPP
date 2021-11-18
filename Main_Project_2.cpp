#include "get_entity.h"
#include "get_states.h"
#include "State.h"
#include "Next_State.h"
#include "Output_Logic.h"
#include "backbone.h"
#include "stimulus.h"
int main()
{
    string FileName = "Moore_design.sv";
    string SpecTable = "State_Table_3.txt";
    array <map <string, array <int, 2>>, 2> Entity;
    array <map <string, vector <string>>, 2> States;
    string module;
    Entity = get_entity(SpecTable);
    States = get_states(SpecTable);

    State(FileName, Entity, States);
    NextState(FileName, Entity, States);
    OutputLogic(FileName, Entity, States);
    //module equal to first value of entity
    module = Entity[0].begin()->first;
    //erase first value of entity
    Entity[0].erase(Entity[0].begin());
    backbone(Entity[0],Entity[1],module);
    stimulus(Entity,States,module);
    return 0;
}