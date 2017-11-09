#现在假设逆希望编写一款程序来追踪一所大学里的老师和学生。又一特征是他们都具有的，例如姓名、年龄和地址。另外一些特征是他们独有的，如教师的薪水、课程与假期，学生的成绩和学费
#你可以为每一种类型创建两个独立的类，并对它们进行处理。但增添一条共有特征就意味着将其添加进两个独立的类。这很快就会使程序变得很笨重
#一个更好的方法是创建一个公共类叫做schoolMember，然后让教师和学生从这个类中继承，也就是说他们将称为这一型（类）的子类型，而我们可以像这些子类型中添加某些类独有的特征

#这种方法由诸多有点。如果我们添加或修改了SchoolMember的任何功能，它将自动反映在子类型中。举个类子，你可以通过简单地向SchoolMember类进行操作，来为所有老师与学生添加一条新的ID卡字段。不过，对某一子类型作出的改动不会映像到其他子类型，这在某些情况下会大为有用，例如清单学校中成员数量。这被称作多态性，在任何情况下，如果父类型希望，子类型都可以被替换，也就是说该对象可以被看作父类的实例。
#同时还需要注意的是我们重用父类的代码，但我们不需要在其他类中重复它们，当我们使用独立类型时才会必要地重复这些代码

#在上文设想的情况中，SchoolMember类会被称作基类(Base Class)或是超类(Superclass).Teacher和Student类会被称作派生类(Derived Class)或者是子类(Subclass)

class SchoolMember:
	'''代表任何学校里的成员'''
	def __init__(self,name,age):
		self.name=name
		self.age=age
		print('(Initialized SchoolMenber: {})'.format(self.name))
	def tell(self):
		'''告诉我有关我的细节'''
		print('name:"{}" Age:"{}"'.format(self.name,self.age),end=" ")
class Teacher(SchoolMember):
	'''代表一位老师'''
	def __init__(self,name,age,salary):
		SchoolMember.__init__(self,name,age)
		self.salary=salary
		print('(Initialized Teacher: {})'.format(self.name))
	def tell(self):
		SchoolMember.tell(self)
		print('Salary: "{:d}"'.format(self.salary))

class Student(SchoolMember):
	'''代表一位学生'''
	def __init__(self,name,age,marks):
		SchoolMember.__init__(self,name,age)
		self.marks=marks
		print('(Initialized Student: {})'.format(self.name))
	def tell(self):
		SchoolMember.tell(self)
		print('Marks: "{:d}"'.format(self.marks))
t=Teacher('Mrs. Shrividya',40,30000)
s=Student('Swaroop',25,75)

#打印一行空白行
print()

members=[t,s]
for member in members:
	member.tell()
#想要使用继承，在定义类时我们需要在类后面跟一个包含基类名称的元组。然后，我们会注意到基类__init__方法是通过self变量被显式调用的，因此我们可以初始化对象的基类部分。下面这点很重要，需要牢记——因为我们在Teacher和Student子类中定义了__init__方法，Python不会自动调用基类SchoolMember的构造函数，你必须自己显式地调用它。
#相反，如果我们没有在一个子类中定义一个__init__方法，Python将会自动调用基类的构造函数
#我们会观察到，我们可以通过在方法名前面加上基类名作为前缀，再传入self和其余变量，来调用基类的方法
#在这里逆需要注意，当我们使用SchoolMember类的tell方法时，我们可以将Teacher或Student的实例看作SchoolMember的实例
#同时，你会发现被调用的是子类型的tell方法，而不是School的方法。来理解这一问题的一种四路是Python总会从当前的实际类型中开始寻找方法，在本例中即是如此。
#end参数用在超类的tell()方法的print函数中，目的是打印一行并允许下一次打印在统一行继续。这是一个让print能够不再末尾打印出\n(新换行符号)的小窍门
