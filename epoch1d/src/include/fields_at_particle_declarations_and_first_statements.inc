    ! Defined at the particle position - 0.5 grid cell in each direction
    ! This is to deal with the grid stagger
    REAL(num), DIMENSION(sf_min-1:sf_max+1) :: hx

    ! Contains the integer cell position of the particle in x, y, z
    INTEGER :: cell_x1, cell_x2, cell_x3

    ! Fields at particle location
    REAL(num) :: ex_part, ey_part, ez_part
    REAL(num) :: bx_part, by_part, bz_part

    INTEGER :: dcellx

    ! Particle weighting multiplication factor
#ifdef PARTICLE_SHAPE_BSPLINE3
    REAL(num) :: cf2
    REAL(num), PARAMETER :: fac = (1.0_num / 24.0_num)**c_ndims
#elif  PARTICLE_SHAPE_TOPHAT
    REAL(num), PARAMETER :: fac = 1.0_num
#else
    REAL(num) :: cf2
    REAL(num), PARAMETER :: fac = (0.5_num)**c_ndims
#endif

    ! Temporary variables
    REAL(num) :: idx

    ! Unvarying multiplication factors
    idx = 1.0_num / dx

    ! These prevent -Werror fail on unused variable
    ! TODO: sort this out so this isn't necessary
    cell_x3 = 0
    cell_x = 0
    cx2 = 0