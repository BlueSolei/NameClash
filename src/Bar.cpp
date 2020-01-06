
#include <string>
#include <memory>

char mem[4096];
int index = 0;

extern "C"
{
    void BarSymbol(int i)
    {

    }

    // ??3@YAXPAXI@Z (void __cdecl operator delete(void *,unsigned int))
    void IAmOpDelete_(void *p,unsigned int size)
    {
		printf("Op Delete free %p of %d bytes\n", p, size);
    }

	// ??2@YAPAXI@Z (void * __cdecl operator new(unsigned int))
	void* IAmOpNew___(unsigned int size)
	{
		void* p = mem + index;
		index += size;
		printf("Op New alloc %p of %d bytes\n", p, size);
		return p;
	}

	// ??2@YAPAXIPAX@Z (void * __cdecl operator new(unsigned int,void *))
	void* IAmOpPlcmntNew(unsigned int size, void *p)
	{
		printf("Placment new: void* operator new(unsigned int: %d, void *p: %p)\n", size, p);
		return p;
	}
}

const char* longString = 
    "111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
    "222222222222222222222222222222222222222222222222222222222222222222222222222222222222"
    "333333333333333333333333333333333333333333333333333333333333333333333333333333333333"
    "444444444444444444444444444444444444444444444444444444444444444444444444444444444444";

struct S
{
    S(int a, std::string str): a(a), str(str) {
        printf("S ctor(%d, %s)\n", a, str.c_str());
    }

    ~S()
    {
        printf("S dtor(%d, %s)\n", a, str.c_str());
    }

    int a = 4;
    std::string str = "Mini string";
};

void UseNewSymbol()
{
    S onStack(1, "On Stack");
    auto onHeap = std::make_unique<S>(2, longString);
}