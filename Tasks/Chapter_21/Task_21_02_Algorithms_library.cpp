#include <iostream>

int main()
try
{
	std::cout << "Algorithms library : \n\n";

	std::cout << "Non - modifying sequence operations : \n";
	std::cout << "all_of\tany_of\tnone_of\n" <<
		"ranges::all_of\tranges::any_of\tranges::none_of\n" <<
		"for_each\n" <<
		"ranges::for_each_n\n" <<
		"count\tcount_if\n" <<
		"mismatch\n" <<
		"ranges::mismatch\n" <<
		"find\tfind_if\tfind_if_not\n" <<
		"ranges::find\tranges::find_if\tranges::find_if_not\n" <<
		"find_end\n" <<
		"ranges::find_end\n" <<
		"find_first_of\n" <<
		"ranges::find_first_of\n" <<
		"adjacent_find\n" <<
		"ranges::adjacent_find\n" <<
		"search\n" <<
		"ranges::search\n" <<
		"search_n\n" <<
		"ranges::search_n\n\n";

	std::cout << "Modifying sequence operations : \n";
	std::cout << "copy\tcopy_if\n" << 
		"ranges::copy\tranges::copy_if\n" <<
		"copy_n\n" <<
		"ranges::copy_n\n" <<
		"copy_backward\n" <<
		"ranges::copy_backward\n" <<
		"move\n" <<
		"ranges::move\n" <<
		"move_backward\n" <<
		"ranges::move_backward\n" <<
		"fill\n" <<
		"ranges::fill\n" <<
		"fill_n\n" <<
		"ranges::fill_n\n" <<
		"transform\n" <<
		"ranges::transform\n" <<
		"generate\n" <<
		"ranges::generate\n" <<
		"generate_n\n" <<
		"ranges::generate_n\n" <<
		"remove\tremove_if\n" <<
		"ranges::remove\tranges::remove_if\n" <<
		"remove_copy\tremove_copy_if\n" <<
		"ranges::remove_copy\tranges::remove_copy_if\n" <<
		"replace\treplace_if\n" <<
		"ranges::replace\tranges::replace_if\n" <<
		"replace_copy\treplace_copy_if\n" <<
		"ranges::replace_copy\tranges::replace_copy_if\n" <<
		"swap\n" <<
		"swap_ranges\n" <<
		"ranges::swap_ranges\n" <<
		"iter_swap\n" <<
		"reverse\n" <<
		"ranges::reverse\n" <<
		"reverse_copy\n" <<
		"ranges::reverse_copy\n" <<
		"rotate\n" <<
		"ranges::rotate\n" <<
		"rotate_copy\n" <<
		"ranges::rotate_copy\n" <<
		"shift_left\tshift_right\n" <<
		"random_shuffle\tshuffle\n" <<
		"ranges::shuffle\n" <<
		"sample\n" <<
		"ranges::sample\n" <<
		"unique\n" <<
		"ranges::unique\n" <<
		"unique_copy\n" <<
		"ranges::unique_copy\n\n";

	std::cout << "Partitioning operations : \n";
	std::cout << "is_partitioned\n" <<
		"ranges::is_partitioned\n" <<
		"partition\n" <<
		"ranges::partition\n" <<
		"partition_copy\n" <<
		"ranges::partition_copy\n" <<
		"stable_partition\n" <<
		"ranges::stable_partition\n" <<
		"partition_point\n" <<
		"ranges::partition_point\n\n";

	std::cout << "Sorting operations : \n";
	std::cout << "is_sorted\n" <<
		"ranges::is_sorted\n" <<
		"is_sorted_until\n" <<
		"ranges::is_sorted_until\n" <<
		"sort\n" <<
		"ranges::sort\n" <<
		"partial_sort\n" <<
		"ranges::partial_sort\n" <<
		"partial_sort_copy\n" <<
		"ranges::partial_sort_copy\n" <<
		"stable_sort\n" <<
		"ranges::stable_sort\n" <<
		"nth_element\n" <<
		"ranges::nth_element\n\n";

	std::cout << "Binary search operations (on sorted ranges) : \n";
	std::cout << "lower_bound\n" <<
		"ranges::lower_bound\n" <<
		"upper_bound\n" <<
		"ranges::upper_bound\n" <<
		"binary_search\n" <<
		"ranges::binary_search\n" <<
		"equal_range\n" <<
		"ranges::equal_range\n\n";

	std::cout << "Other operations on sorted ranges : \n";
	std::cout << "merge\n" <<
		"ranges::merge\n" <<
		"inplace_merge\n" <<
		"ranges::inplace_merge\n\n";

	std::cout << "Set operations (on sorted ranges) : \n";
	std::cout << "includes\n" <<
		"ranges::includes\n" <<
		"set_difference\n" <<
		"ranges::set_difference\n" <<
		"set_intersection\n" <<
		"ranges::set_intersection\n" <<
		"set_symmetric_difference\n" <<
		"ranges::set_symmetric_difference\n" <<
		"set_union\n" <<
		"ranges::set_union\n\n";

	std::cout << "Heap operations : \n";
	std::cout << "is_heap\n" <<
		"ranges::is_heap\n" <<
		"is_heap_until\n" <<
		"ranges::is_heap_until\n" <<
		"make_heap\n" <<
		"ranges::make_heap\n" <<
		"push_heap\n" <<
		"ranges::push_heap\n" <<
		"pop_heap\n" <<
		"ranges::pop_heap\n" <<
		"sort_heap\n" <<
		"ranges::sort_heap\n\n";

	std::cout << "Minimum/maximum operations : \n";
	std::cout << "max\n" <<
		"ranges::max\n" <<
		"max_element\n" <<
		"ranges::max_element\n" <<
		"min\n" <<
		"ranges::min\n" <<
		"min_element\n" <<
		"ranges::min_element\n" <<
		"minmax\n" <<
		"ranges::minmax\n" <<
		"minmax_element\n" <<
		"ranges::minmax_element\n" <<
		"clamp\n" <<
		"ranges::clamp\n\n";

	std::cout << "Comparison operations : \n";
	std::cout << "equal\n" <<
		"ranges::equal\n" <<
		"lexicographical_compare\n" <<
		"ranges::lexicographical_compare\n" <<
		"lexicographical_compare_three_way\n\n";

	std::cout << "Permutation operations : \n";
	std::cout << "is_permutation\n" <<
		"ranges::is_permutation\n" <<
		"next_permutation\n" <<
		"ranges::next_permutation\n" <<
		"prev_permutation\n" <<
		"ranges::prev_permutation\n\n";

	std::cout << "Numeric operations : \n";
	std::cout << "iota\n" <<
		"accumulate\n" <<
		"inner_product\n" <<
		"adjacent_difference\n" <<
		"partial_sum\n" <<
		"reduce\n" <<
		"exclusive_scan\n" <<
		"inclusive_scan\n" <<
		"transform_reduce\n" <<
		"transform_exclusive_scan\n" <<
		"transform_inclusive_scan\n\n";

	std::cout << "Operations on uninitialized memory : \n";
	std::cout << "uninitialized_copy\n" <<
		"ranges::uninitialized_copy\n" <<
		"uninitialized_copy_n\n" <<
		"ranges::uninitialized_copy_n\n" <<
		"uninitialized_fill\n" <<
		"ranges::uninitialized_fill\n" <<
		"uninitialized_fill_n\n" <<
		"ranges::uninitialized_fill_n\n" <<
		"uninitialized_move\n" <<
		"ranges::uninitialized_move\n" <<
		"uninitialized_move_n\n" <<
		"ranges::uninitialized_move_n\n" <<
		"uninitialized_default_construct\n" <<
		"ranges::uninitialized_default_construct\n" <<
		"uninitialized_default_construct_n\n" <<
		"ranges::uninitialized_default_construct_n\n" <<
		"uninitialized_value_construct\n" <<
		"ranges::uninitialized_value_construct\n" <<
		"uninitialized_value_construct_n\n" <<
		"ranges::uninitialized_value_construct_n\n" <<
		"destroy\n" <<
		"ranges::destroy\n" <<
		"destroy_n\n" <<
		"ranges::destroy_n\n" <<
		"destroy_at\n" <<
		"ranges::destroy_at\n" <<
		"construct_at\n" <<
		"ranges::construct_at\n\n";

	std::cout << "C library : \n";
	std::cout << "qsort\n" <<
		"bsearch\n\n";
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}