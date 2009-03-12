#ifndef  SDAIEXAMPLE_SCHEMA_INIT_CC
#define  SDAIEXAMPLE_SCHEMA_INIT_CC
// This file was generated by fedex_plus.  You probably don't want to edit
// it since your modifications will be lost if fedex_plus is used to
// regenerate it.
/* $Id$ */
#ifndef  SCHEMA_H
#include <schema.h>
#endif
#include <Registry.h>
void 
SdaiEXAMPLE_SCHEMAInit (Registry& reg)
{
	reg.AddType (*example_schemat_color);
	example_schemat_label->ReferentType(t_sdaiSTRING);
	reg.AddType (*example_schemat_label);
	example_schemat_point->ReferentType(t_sdaiREAL);
	reg.AddType (*example_schemat_point);
	example_schemat_length_measure->ReferentType(t_sdaiREAL);
	reg.AddType (*example_schemat_length_measure);

/////////	 ENTITY poly_line

	ListTypeDescriptor * t_0 = new ListTypeDescriptor;
	t_0->AssignAggrCreator((AggregateCreator) create_EntityAggregate);	// Creator function 
	t_0->FundamentalType(LIST_TYPE);
	t_0->Description("LIST OF line");
	t_0->OriginatingSchema(s_example_schema);
	t_0->ReferentType(example_schemae_line);
  a_0points =
	  new AttrDescriptor("points",t_0,SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_poly_line);
	example_schemae_poly_line->AddExplicitAttr (a_0points);
	reg.AddEntity (*example_schemae_poly_line);
/////////	 END_ENTITY poly_line

/////////	 ENTITY shape

	example_schemae_shape->AddSupertype_Stmt("SUPERTYPE OF (ONEOF (circle,triangle,rectangle))");
  a_1item_name =
	  new AttrDescriptor("item_name",example_schemat_label,
	  SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_shape);
	example_schemae_shape->AddExplicitAttr (a_1item_name);
  a_2item_color =
	  new AttrDescriptor("item_color",example_schemat_color,
	  SCLLOG(LTrue),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_shape);
	example_schemae_shape->AddExplicitAttr (a_2item_color);
  a_3number_of_sides =
	  new AttrDescriptor("number_of_sides",t_sdaiINTEGER,
	  SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_shape);
	example_schemae_shape->AddExplicitAttr (a_3number_of_sides);
	reg.AddEntity (*example_schemae_shape);
/////////	 END_ENTITY shape

/////////	 ENTITY rectangle

	example_schemae_rectangle->AddSupertype_Stmt("SUPERTYPE OF (square)");
	example_schemae_rectangle->AddSupertype(example_schemae_shape);
	example_schemae_shape->AddSubtype(example_schemae_rectangle);
  a_4height =
	  new AttrDescriptor("height",example_schemat_length_measure,
	  SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_rectangle);
	example_schemae_rectangle->AddExplicitAttr (a_4height);
  a_5width =
	  new AttrDescriptor("width",example_schemat_length_measure,
	  SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_rectangle);
	example_schemae_rectangle->AddExplicitAttr (a_5width);
	reg.AddEntity (*example_schemae_rectangle);
/////////	 END_ENTITY rectangle

/////////	 ENTITY square

	example_schemae_square->AddSupertype(example_schemae_rectangle);
	example_schemae_rectangle->AddSubtype(example_schemae_square);
	reg.AddEntity (*example_schemae_square);
/////////	 END_ENTITY square

/////////	 ENTITY triangle

	example_schemae_triangle->AddSupertype(example_schemae_shape);
	example_schemae_shape->AddSubtype(example_schemae_triangle);
  a_6side1_length =
	  new AttrDescriptor("side1_length",example_schemat_length_measure,
	  SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_triangle);
	example_schemae_triangle->AddExplicitAttr (a_6side1_length);
  a_7side2_length =
	  new AttrDescriptor("side2_length",example_schemat_length_measure,
	  SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_triangle);
	example_schemae_triangle->AddExplicitAttr (a_7side2_length);
  a_8side3_length =
	  new AttrDescriptor("side3_length",example_schemat_length_measure,
	  SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_triangle);
	example_schemae_triangle->AddExplicitAttr (a_8side3_length);
	reg.AddEntity (*example_schemae_triangle);
/////////	 END_ENTITY triangle

/////////	 ENTITY circle

	example_schemae_circle->AddSupertype(example_schemae_shape);
	example_schemae_shape->AddSubtype(example_schemae_circle);
  a_9radius =
	  new AttrDescriptor("radius",t_sdaiREAL,
	  SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_circle);
	example_schemae_circle->AddExplicitAttr (a_9radius);
	reg.AddEntity (*example_schemae_circle);
/////////	 END_ENTITY circle

/////////	 ENTITY line

	a_10end_point_one =
	  new AttrDescriptor("end_point_one",example_schemae_cartesian_point,
	  SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_line);
	example_schemae_line->AddExplicitAttr (a_10end_point_one);
	a_11end_point_two =
	  new AttrDescriptor("end_point_two",example_schemae_cartesian_point,
	  SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_line);
	example_schemae_line->AddExplicitAttr (a_11end_point_two);
	reg.AddEntity (*example_schemae_line);
/////////	 END_ENTITY line

/////////	 ENTITY cartesian_point

  a_12x =
	  new AttrDescriptor("x",example_schemat_point,
	  SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_cartesian_point);
	example_schemae_cartesian_point->AddExplicitAttr (a_12x);
  a_13y =
	  new AttrDescriptor("y",example_schemat_point,
	  SCLLOG(LFalse),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_cartesian_point);
	example_schemae_cartesian_point->AddExplicitAttr (a_13y);
  a_14z =
	  new AttrDescriptor("z",example_schemat_point,
	  SCLLOG(LTrue),SCLLOG(LFalse), AttrType_Explicit,
	  *example_schemae_cartesian_point);
	example_schemae_cartesian_point->AddExplicitAttr (a_14z);
	reg.AddEntity (*example_schemae_cartesian_point);
/////////	 END_ENTITY cartesian_point

}
#endif
