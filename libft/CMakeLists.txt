cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 11)

project(libft C)

add_compile_options(-Wall -Wextra)

if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    add_compile_options(-O2 -Werror)
endif()

include_directories(includes)

set(src_atoi_itoa
        src_atoi_itoa/ft_atoi.c
        src_atoi_itoa/ft_atoll.c
        src_atoi_itoa/ft_atoll_base.c
        src_atoi_itoa/ft_atoull.c
        src_atoi_itoa/ft_itoa.c
        src_atoi_itoa/ft_lltoa.c
        src_atoi_itoa/ft_lltoa_base.c
        src_atoi_itoa/ft_ulltoa.c
        src_atoi_itoa/ft_ulltoa_base.c
        src_atoi_itoa/ft_strtod.c
        )

set(src_list
        src_list/ft_lstadd.c
        src_list/ft_lstaddback.c
        src_list/ft_lstaddback_p.c
        src_list/ft_lstdel.c
        src_list/ft_lstdel_p.c
        src_list/ft_lstdelone.c
        src_list/ft_lstiter.c
        src_list/ft_lstmap.c
        src_list/ft_lstnew.c
        src_list/ft_lstnew_p.c
        src_list/ft_lstprint.c
        )

set(src_math
        src_math/ft_abs.c
        src_math/ft_power.c
        src_math/ft_swap.c
        src_math/is_even.c
        src_math/ft_max.c
        src_math/ft_min.c
        )

set(src_memory
        src_memory/clean_chr_mtrx.c
        src_memory/ft_bzero.c
        src_memory/ft_memalloc.c
        src_memory/ft_memccpy.c
        src_memory/ft_memchr.c
        src_memory/ft_memcmp.c
        src_memory/ft_memcpy.c
        src_memory/ft_memdel.c
        src_memory/ft_memmove.c
        src_memory/ft_memset.c
        )

set(src_put
        src_put/ft_putchar.c
        src_put/ft_putchar_fd.c
        src_put/ft_putendl.c
        src_put/ft_putendl_fd.c
        src_put/ft_putnbr.c
        src_put/ft_putnbr_fd.c
        src_put/ft_putstr.c
        src_put/ft_putstr_fd.c)

set(src_string
        src_string/ft_strcat.c
        src_string/ft_strchr.c
        src_string/ft_strclr.c
        src_string/ft_strcmp.c
        src_string/ft_strcpy.c
        src_string/ft_strdel.c
        src_string/ft_strdup.c
        src_string/ft_strequ.c
        src_string/ft_striter.c
        src_string/ft_striteri.c
        src_string/ft_strjoin.c
        src_string/ft_strlcat.c
        src_string/ft_strlen.c
        src_string/ft_strlen_char.c
        src_string/ft_strljoin.c
        src_string/ft_strmap.c
        src_string/ft_strmapi.c
        src_string/ft_strncat.c
        src_string/ft_strncmp.c
        src_string/ft_strncpy.c
        src_string/ft_strnequ.c
        src_string/ft_strnew.c
        src_string/ft_strnstr.c
        src_string/ft_strrchr.c
        src_string/ft_strsplit.c
        src_string/ft_strstr.c
        src_string/ft_strsub.c
        src_string/ft_strtrim.c
        src_string/ft_tolower.c
        src_string/ft_toupper.c
        src_string/ft_trim_c.c
        src_string/get_next_line.c
        src_string/ft_readfile.c
        src_string/gnl.c
        )

set(src_utils
        src_utils/ft_count_digits.c
        src_utils/ft_count_digits_base.c
        src_utils/ft_isalnum.c
        src_utils/ft_isalpha.c
        src_utils/ft_isascii.c
        src_utils/ft_isdigit.c
        src_utils/ft_isprint.c
        src_utils/ft_isspace.c
        src_utils/pass_spaces.c
        )

set(src_binary_trees
        src_binary_trees/btree_create_node.c
        src_binary_trees/btree_insert_data.c
        src_binary_trees/btree_apply_preorder.c
        src_binary_trees/btree_apply_inorder.c
        src_binary_trees/btree_apply_postorder.c
        src_binary_trees/btree_find_item.c
        src_binary_trees/btree_level_count.c
        src_binary_trees/avl_tree_create_node.c
        src_binary_trees/avl_tree_helper_functions.c
        src_binary_trees/avl_tree_rebalancing.c
        src_binary_trees/avl_insert_data.c
        src_binary_trees/avl_delete_node.c
        src_binary_trees/free_btree.c
        )

set(test
        test/main.c
        test/test_asserts.c
        test/btree_test_functions.c
        test/profiling_tests.c
        test/avl_tree_test_functions.c
        test/test_strtod.c
        test/test_get_next_line.c)

add_library(ft STATIC
        ${src_atoi_itoa}
        ${src_list}
        ${src_math}
        ${src_memory}
        ${src_put}
        ${src_string}
        ${src_utils}
        ${src_binary_trees}
        )

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    link_directories(cmake-build-debug)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    link_directories(cmake-build-release)
endif()

link_directories(ft_printf)

add_executable(test
        ${test}
        )

target_link_libraries(test
        "ft"
        "ftprintf")
