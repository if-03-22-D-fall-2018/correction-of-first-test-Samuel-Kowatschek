/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			grade_list.c
 * Author:			P. Bauer
 * Due Date:		November 18, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of grade_list.h.
 * ----------------------------------------------------------
 */

 #include "process_list.h"
void init_process_list(ProcessList* pl){
  pl->length=0;
}
int get_length(const ProcessList* pl){
  return pl->length;
}

bool add_entry(ProcessList* pl, struct ProcessListEntry* entry){
  if(pl->length>=MAX_LIST_ENTRIES){
    return false;
  }
  pl->processes[pl->length]=entry;
  pl->length++;
  return true;
}

bool add_entries(ProcessList* pl, struct ProcessListEntry* entries[], int quantity){
  if (pl->length+quantity>MAX_LIST_ENTRIES) {
    return false;
  }
  for (int i = 0; i < quantity; i++) {
    add_entry(pl, entries[i]);
  }
  return true;
}

int get_process_with_id(const ProcessList* pl, int id, struct ProcessListEntry* result_list[]){
  int found=0;
  for (int i = 0; i < pl->length; i++) {
    if (id==pl->processes[i]->pid) {
      result_list[found]->pid=id;
      found++;
    }
  }
  return found;
}

int get_processes_with_state(const ProcessList* pl, enum ProcessState state, struct ProcessListEntry* result_list[]){
  int found=0;
  for (int i= 0; i < pl->length; i++) {
    if (state==pl->processes[i]->state){
      result_list[found]=pl->processes[i];    //habe der ergebnisliste an der stelle found den selben Process zugewiesen wie der "normalen" Liste an der Stelle i
      found++;
    }
  }
  return found;
}

struct ProcessListEntry* get_process_with_highest_cpu_consumption(const ProcessList* pl){
  int actual_highest_usage=0;   //variablenname von entry_of_highest_time auf entry_of_highest_usage geändert
  struct ProcessListEntry* entry_of_highest_usage=0; //hier veränderte ich den wert der variable auf 0 und ich habe den variablennamen geändert
  for (int i = 0; i < pl->length; i++) {
      if(pl->processes[i]->cpu_usage > actual_highest_usage){//changed time to cpu_usage
        actual_highest_usage=pl->processes[i]->cpu_usage;//changed time to cpu_usage
        entry_of_highest_usage=pl->processes[i];
    }
  }
  return entry_of_highest_usage;
}

struct ProcessListEntry* get_process_with_lowest_cpu_consumption(const ProcessList* pl){
  int current_lowest_usage=pl->processes[0]->cpu_usage;     //changed the names of the variable and changed the value to the first entry for cpu usage of processes
  struct ProcessListEntry* entry_of_lowest_cpu_usage = pl->processes[0]; //changed the name of the variable and gave it the value of the first process
  if(pl->length==0){                                              //added an if to see if my dick is hard
    return 0;
  }
  for (int i = 0; i < pl->length; i++) {
      if(pl->processes[i]->cpu_usage < current_lowest_usage){  //changed time to cpu_usage, changed a '>' to '<' and i changed the names of the variable
        current_lowest_usage=pl->processes[i]->cpu_usage; //changed time to cpu_usage
        entry_of_lowest_cpu_usage=pl->processes[i];
    }
  }
  return entry_of_lowest_cpu_usage;
}


int get_top_n_processes_cpu(const ProcessList* pl, int quantity, struct ProcessListEntry* result_list[]){
  return 0;
}


int get_bottom_n_processes_cpu(const ProcessList* pl, int quantity, struct ProcessListEntry* result_list[]){
  return 0;
}
