void pk()
{
	__asm__(
		"ldr r7,=366 \n"
		"swi \n"
		:
		:
		:"memory");
}

int main()
{
	pk();

	return 0;
}
