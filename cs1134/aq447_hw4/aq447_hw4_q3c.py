def print_ruler(n):
    if(n <= 1):
        print("-" * n)
        return
    print_ruler(n-1)
    print("-" * n)
    print_ruler(n-1)

