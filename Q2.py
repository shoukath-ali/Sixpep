#Student CMS
import random
import string
import json
def generator():
  return ''.join(random.choices(string.digits + string.ascii_uppercase + string.ascii_lowercase,k=6))

def display():
  print('1.Add 2.Update 3.Delete 4.View 5.Save & Quit')

def main():
  try:
  #check file ->if not present -> create file 
   with open('student_data.json', 'rb') as f:
       if f.read(2) != '[]':
          f.seek(0)  # it may be redundant but it does not hurt
       else:
         with open('student_data.json', 'w') as f:  #to initialise if file is empty
             json.dump({ }, f, indent=2)
  except:#if file is not present create one
    with open('student_data.json', 'w') as f:
              json.dump({ }, f, indent=2)

  #load data from file
  with open('student_data.json') as f:
      student = json.load(f)
  #input starts here
  ip = 0
  while(ip!=5):
    display()
    ip = int(input())
    details = {}
    if(ip==1):
        print("Add New student details in [name, age, city] seperated by comma:\n")
        details['name'],details['age'],details['city'] = input().split(",")
        details['id'] = generator()
        # try:
        details['name'].isdigit()
        details['city'].isdigit()
        # except:
        try:
          details['age']=int(details['age'])
          if(details['name']==" " or details['age']==" " or details['city']==" "): #check for compulsory values and not null
            print("Invalid Input")
          elif(details['name'].isdigit() or details['city'].isdigit()):
            print("Invalid Input")
          else:
            student[details['id']] = details
            # record_id.append(details['id'])
          print("Added successfully with id:",details['id'])
        except:
            print("Invalid Input")
    if(ip==2): #Update the values wrt format specified and Implemented with error handling
      print("Update the values in format id,name,age,city. blank values doesn't change\n")
      try:
        id,name,age,city = input().split(",")
      except:
          print("Invalid data, try again")
      try:
        if(id in student.keys()):
          if(name.isdigit()):
            print("Invalid name data Input")
          if(city.isdigit()):
            print("Invalid city data Input")
          if(age!=""):
            try:
              age=int(age)
            except:
              print("Invalid age data, Try again")
          else:
            if(name!=""):
               student[id]['name'] = name
            if(age!=""):
              student[id]['age'] = age
            if(city!=""):
              student[id]['city'] = city
        else:
          print("ID not found")
      except UnboundLocalError:
          print("Invalid data Format,try again!")
      except:
        print("Invalid data Format,try again!")
    if(ip==3): #Delete data from Content Management
      print("enter id to delete")
      id = input()
      if(id in student.keys()):
        del student[id]
        # record_id.remove(id)
        print("deleted successfully")
      else:
        print("ID not found")
    if(ip==4): # Show or Query data from CMS
      print("Enter ID to show details or  conditional query like age>20,city=='hyd', >,<,=,&& ")
      cond_student = student
      data = input()
      flag = False
      if(data in student.keys()):
        print(f"name: {student[data]['name']}, age :{student[data]['age']}, city: {student[data]['city']}")
      else:
        condition = data.split('&&')
        for i in condition:
         if(i.find('=')!=-1):
           i = i.split('=')
           for j in student.keys():
               cond_student = {key:value for (key,value) in cond_student.items() if str(value[i[0]]) ==i[1]}
         elif(i.find('>')!=-1):
           i = i.split('>')
           for j in student.keys():
              cond_student = {key:value for (key,value) in cond_student.items() if value[i[0]] > int(i[1])}
         elif(i.find('<')!=-1):
            i = i.split('<')
            for j in student.keys():
               cond_student = {key:value for (key,value) in cond_student.items() if value[i[0]] > int(i[1])}
         else:
           print("Invalid condition/ Data NotFound")
           flag = True
        if(not(flag)):
          for (key,value) in cond_student.items():
            print(f"name: {cond_student[key]['name']}, age :{cond_student[key]['age']}, city: {cond_student[key]['city']}")
    if(ip==5): #Save data in a FileJSwA1z
      with open('student_data.json', 'w') as f:
        json.dump(student, f, indent=2)
      return
    elif(ip>5):
      print("Invalid Input, returning without saving");
      return

if __name__ == "__main__":
    main()