
// DEFINING INLINE FUNCTIONS IN CLASSES

// Variant #1: definition of cube() inside the class declaration => cube() becomes inline automatically!

class B
{
	public:
		int cube(int a)
		{
			return a*a*a;
		}
};


//-----------------------

// Variant #2: definition of cube() outside the class declaration.
// If you want this function to become "inline", you should write inline explicitly!

class B
{
	int cube(int a);
}

inline int B::cube(int a)
{
	return a;
}