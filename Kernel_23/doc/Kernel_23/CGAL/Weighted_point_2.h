namespace CGAL {

/*!
\ingroup kernel_classes2

An object of the class `Weighted_point_2` is a tuple of a two-dimensional point and a scalar weight.

Remember that `Kernel::RT` and `Kernel::FT` denote a
`RingNumberType` and a `FieldNumberType`, respectively. For the kernel
model `Cartesian<NT>`, the two types are the same. For the
kernel model `Homogeneous<NT>`, `Kernel::RT` is equal
to `NT`, and `Kernel::FT` is equal to `Quotient<NT>`.

\sa `Point_2<Kernel>`

\cgalModels `Kernel::WeightedPoint_2`

*/
template< typename Kernel >
class Weighted_point_2
{
public:
  /// \name Types
  /// @{

  /*!
  An iterator for enumerating the
  %Cartesian coordinates of a point.
  */
  typedef unspecified_type                Cartesian_const_iterator;

  /// @}

  /// \name Creation
  ///  Constructors from coordinates are provided for convenience, except
  ///  that they are only from Cartesian coordinates, and with no weight, so as
  ///  to avoid any potential ambiguity between the homogeneous weight and the
  ///  power weight (it should be easy enough to pass a Point_2 explicitly in those
  ///  cases).

  /// @{

  /*!
  introduces a weighted point with %Cartesian coordinates `(0,0)` and weight `0`.
  */
  Weighted_point_2(const Origin &ORIGIN);

  /*!
  introduces a weighted point from point `p` and weight `0`.

  \warning The `explicit` keyword is used to not have accidental implicit conversions
           between Point_2 and Weighted_point_2.
  */
  explicit Weighted_point_2(const Point_2<Kernel>& p);

  /*!
  introduces a weighted point from point `p` and weight `w`.
  */
  Weighted_point_2(const Point_2<Kernel>& p, Kernel::FT& w);

  /*!
  introduces a weighted point with coordinates `x`, `y`, and weight `0`.
  */
  Weighted_point_2(const Kernel::FT& x, const Kernel::FT& y);

  /// @}

  /// \name Bare point and weight accessors
  /// @{

  /*!
  returns the point of the weighted point.
  */
  Point_2<Kernel> point() const;

  /*!
  returns the weight of the weighted point.
  */
  Kernel::FT weight() const;
  /// @}

  /// \name Operations
  ///
  /// \warning Comparison and equality operators (==, !=, <, etc.) currently operate
  /// directly on the underlying bare point. Consequently:
  /// \code
  /// Point_2< Cartesian<double> > p(1.0, 2.0);
  /// Weighted_point_2< Cartesian<double> > wp(p, 1.0), wq(p, 2.0); // same bare point, but different weights
  /// wp == wq; // is equal to `true`
  /// \endcode
  /// @{

  /*!
  Test for equality. Two points are equal, iff their \f$ x\f$ and \f$ y\f$
  coordinates are equal. The point can be compared with `ORIGIN`.
  */
  bool operator==(const Weighted_point_2<Kernel> &q) const;

  /*!
  Test for inequality. The point can be compared with `ORIGIN`.
  */
  bool operator!=(const Weighted_point_2<Kernel> &q) const;

  /*!
  translates the point by the vector `v`.
  */
  Weighted_point_2<Kernel>& operator+=(const Vector_2<Kernel> &v);

  /*!
  translates the point by the vector -`v`.
  */
  Weighted_point_2<Kernel>& operator-=(const Vector_2<Kernel> &v);

  /// @}

  /// \name Coordinate Access
  /// There are two sets of coordinate access functions, namely to the
  /// homogeneous and to the %Cartesian coordinates. They can be used
  /// independently from the chosen kernel model. Note that you do not
  /// loose information with the homogeneous representation, because the
  /// `FieldNumberType` is a quotient.
  /// @{

  /*!
  returns the homogeneous \f$ x\f$ coordinate.
  */
  Kernel::RT hx() const;

  /*!
  returns the homogeneous \f$ y\f$ coordinate.
  */
  Kernel::RT hy() const;

  /*!
  returns the homogenizing coordinate.
  */
  Kernel::RT hw() const;

  /*!
  returns the %Cartesian \f$ x\f$ coordinate, that is `hx()`/`hw()`.
  */
  Kernel::FT x() const;

  /*!
  returns the %Cartesian \f$ y\f$ coordinate, that is `hy()`/`hw()`.
  */
  Kernel::FT y() const;

  /// @}

  /// \name Convenience Operations
  /// The following operations are for convenience and for compatibility
  /// with higher dimensional points. Again they come in a %Cartesian and
  /// in a homogeneous flavor.
  /// @{

  /*!
  returns the i'th homogeneous coordinate of `p`, starting with 0.
  \pre \f$ 0\leq i \leq2\f$.
  */
  Kernel::RT homogeneous(int i) const;

  /*!
  returns the i'th %Cartesian coordinate of `p`, starting with 0.
  \pre \f$ 0\leq i \leq1\f$.
  */
  Kernel::FT cartesian(int i) const;

  /*!
  returns `cartesian(i)`.
  \pre \f$ 0\leq i \leq1\f$.
  */
  Kernel::FT operator[](int i) const;

  /*!
  returns an iterator to the %Cartesian coordinates
  of `p`, starting with the 0th coordinate.
  */
  Cartesian_const_iterator cartesian_begin() const;

  /*!
  returns an off the end iterator to the Cartesian
  coordinates of `p`.
  */
  Cartesian_const_iterator cartesian_end() const;

  /*!
  returns the dimension (the constant 2).
  */
  int dimension() const;

  /*!
  returns a bounding box containing `p`. Note that bounding boxes
  are not parameterized with whatsoever.
  */
  Bbox_2 bbox() const;

  /*!
  returns the weighted point obtained by applying `t` on `p`.
  */
  Weighted_point_2<Kernel> transform(const Aff_transformation_2<Kernel> &t) const;

  /// @}

}; /* end Weighted_point_2 */

} /* end namespace CGAL */
