struct imports_t
{
	uintptr_t ps_lookup_process_by_process_id;
	uintptr_t io_get_current_process;
	uintptr_t mm_get_virtual_for_physical;
	uintptr_t mm_unmap_locked_pages;
	uintptr_t mm_free_pages_from_mdl;
	uintptr_t mm_map_locked_pages_specify_cache;
	uintptr_t mm_protect_mdl_system_address;
	uintptr_t mm_allocate_pages_for_mdl;
	uintptr_t mm_copy_memory;
	uintptr_t ex_get_previous_mode;
};

imports_t imports;

NTSTATUS ps_lookup_process_by_process_id( HANDLE ProcessId, PEPROCESS* Process )
{
	return reinterpret_cast< NTSTATUS( * )( HANDLE, PEPROCESS * ) > ( imports.ps_lookup_process_by_process_id )( ProcessId, Process );
}

PEPROCESS io_get_current_process( )
{
	return reinterpret_cast< PEPROCESS( * )( ) > ( imports.io_get_current_process )( );
}

PVOID mm_get_virtual_for_physical( PHYSICAL_ADDRESS PhysicalAddress )
{
	return reinterpret_cast< PVOID( * )( PHYSICAL_ADDRESS ) > ( imports.mm_get_virtual_for_physical )( PhysicalAddress );
}

void mm_unmap_locked_pages( PVOID BaseAddress, PMDL MemoryDescriptorList )
{
	return reinterpret_cast< void( * )( PVOID, PMDL ) > ( imports.mm_unmap_locked_pages )( BaseAddress, MemoryDescriptorList );
}

void mm_free_pages_from_mdl( PMDL MemoryDescriptorList )
{
	return reinterpret_cast< void( * )( PMDL ) > ( imports.mm_free_pages_from_mdl )( MemoryDescriptorList );
}

PVOID mm_map_locked_pages_specify_cache( PMDL MemoryDescriptorList, KPROCESSOR_MODE AccessMode, MEMORY_CACHING_TYPE CacheType, PVOID RequestedAddress, ULONG BugCheckOnFailure, ULONG Priority )
{
	return reinterpret_cast< PVOID( * )( PMDL, KPROCESSOR_MODE, MEMORY_CACHING_TYPE, PVOID, ULONG, ULONG ) > ( imports.mm_map_locked_pages_specify_cache )( MemoryDescriptorList, AccessMode, CacheType, RequestedAddress, BugCheckOnFailure, Priority );
}

NTSTATUS mm_protect_mdl_system_address( PMDL MemoryDescriptorList, ULONG NewProtect )
{
	return reinterpret_cast< NTSTATUS( * )( PMDL, ULONG ) > ( imports.mm_protect_mdl_system_address )( MemoryDescriptorList, NewProtect );
}

PMDL mm_allocate_pages_for_mdl( PHYSICAL_ADDRESS LowAddress, PHYSICAL_ADDRESS HighAddress, PHYSICAL_ADDRESS SkipBytes, SIZE_T TotalBytes )
{
	return reinterpret_cast< PMDL( * )( PHYSICAL_ADDRESS, PHYSICAL_ADDRESS, PHYSICAL_ADDRESS, SIZE_T ) > ( imports.mm_allocate_pages_for_mdl )( LowAddress, HighAddress, SkipBytes, TotalBytes );
}

NTSTATUS mm_copy_memory( PVOID TargetAddress, MM_COPY_ADDRESS SourceAddress, SIZE_T NumberOfBytes, ULONG Flags, PSIZE_T NumberOfBytesTransferred )
{
	return reinterpret_cast< NTSTATUS( * )( PVOID, MM_COPY_ADDRESS, SIZE_T, ULONG, PSIZE_T ) > ( imports.mm_allocate_pages_for_mdl )( TargetAddress, SourceAddress, NumberOfBytes, Flags, NumberOfBytesTransferred );
}

KPROCESSOR_MODE ex_get_previous_mode( )
{
	return reinterpret_cast< KPROCESSOR_MODE( * )( ) >( imports.ex_get_previous_mode )( );
}