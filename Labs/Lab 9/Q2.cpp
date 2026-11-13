
#include <bits/stdc++.h>
using namespace std;

class EmployeeNode
{
public:
    int id;
    string name;
    string department;
    EmployeeNode *left;
    EmployeeNode *right;

    EmployeeNode(int i, string n, string dep)
    {
        id = i;
        name = n;
        department = dep;
        left = right = NULL;
    }
};

class EmployeeBST
{
public:
    EmployeeNode *root;

    EmployeeBST()
    {
        root = NULL;
    }

    void insert(int id, string name, string department)
    {
        EmployeeNode* newNode = new EmployeeNode(id, name, department);

        if(root == NULL)
        {
            root = newNode;
            return;
        }

        EmployeeNode* current = root;

        while(true)
        {
            if(current->id == id)
            {
                cout << "Duplicate ID" << endl;
                delete newNode;
                return;
            }
            else if(current->id < id)
            {
                if(current->right == NULL)
                {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
            else
            {
                if(current->left == NULL)
                {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            }
        }
    }

    EmployeeNode* search(int id)
    {
        EmployeeNode* current = root;

        while(current != NULL)
        {
            if(current->id == id)
                return current;

            if(id < current->id)
                current = current->left;
            else
                current = current->right;
        }

        return NULL;
    }

    void displayInorder(EmployeeNode* current)
    {
        if(current == NULL) return;

        displayInorder(current->left);

        cout << "ID: " << current->id
             << " | Name: " << current->name
             << " | Department: " << current->department << endl;

        displayInorder(current->right);
    }

    void display()
    {
        if(root == NULL)
        {
            cout << "Employee list is empty." << endl;
            return;
        }

        displayInorder(root);
    }

    EmployeeNode* findMin()
    {
        if(root == NULL) return NULL;

        EmployeeNode* current = root;

        while(current->left != NULL)
            current = current->left;

        return current;
    }

    EmployeeNode* findMax()
    {
        if(root == NULL) return NULL;

        EmployeeNode* current = root;

        while(current->right != NULL)
            current = current->right;

        return current;
    }

    EmployeeNode* deleteNode(EmployeeNode* current, int id)
    {
        if(current == NULL)
            return NULL;

        if(id < current->id)
        {
            current->left = deleteNode(current->left, id);
        }
        else if(id > current->id)
        {
            current->right = deleteNode(current->right, id);
        }
        else
        {
            if(current->left == NULL && current->right == NULL)
            {
                delete current;
                return NULL;
            }
            else if(current->left == NULL)
            {
                EmployeeNode* temp = current->right;
                delete current;
                return temp;
            }
            else if(current->right == NULL)
            {
                EmployeeNode* temp = current->left;
                delete current;
                return temp;
            }
            else
            {
                EmployeeNode* temp = current->right;

                while(temp->left != NULL)
                    temp = temp->left;

                current->id = temp->id;
                current->name = temp->name;
                current->department = temp->department;

                current->right = deleteNode(current->right, temp->id);
            }
        }

        return current;
    }

    void removeEmployee(int id)
    {
        if(search(id) == NULL)
        {
            cout << "Employee ID not found." << endl;
            return;
        }

        root = deleteNode(root, id);
        cout << "Employee deleted successfully." << endl;
    }
};

int main()
{
    EmployeeBST employees;

    employees.insert(105, "Ali", "IT");
    employees.insert(102, "Sara", "HR");
    employees.insert(110, "Ahmed", "Finance");
    employees.insert(101, "Hina", "Marketing");
    employees.insert(108, "Usman", "IT");

    cout << "Employees in ascending order of ID:" << endl;
    employees.display();

    int id = 108;
    EmployeeNode* employee = employees.search(id);

    if(employee != NULL)
    {
        cout << "\nEmployee found:" << endl;
        cout << "ID: " << employee->id
             << ", Name: " << employee->name
             << ", Department: " << employee->department << endl;
    }
    else
    {
        cout << "\nEmployee not found." << endl;
    }

    EmployeeNode* minimum = employees.findMin();

    if(minimum != NULL)
    {
        cout << "\nEmployee with minimum ID:" << endl;
        cout << minimum->id << " - " << minimum->name << endl;
    }

    EmployeeNode* maximum = employees.findMax();

    if(maximum != NULL)
    {
        cout << "\nEmployee with maximum ID:" << endl;
        cout << maximum->id << " - " << maximum->name << endl;
    }

    cout << "\nDeleting employee with ID 105:" << endl;
    employees.removeEmployee(105);

    cout << "\nUpdated Employee List:" << endl;
    employees.display();

    return 0;
}
