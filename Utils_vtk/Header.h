#pragma once
#define ERR_RETURN(a) {printf(a); return 1;}

#define RELEASE_VER

#define USE_VTK

#include "string"
#include "iostream"
#include "fstream"

#include <eigen3/Eigen/Dense>
typedef Eigen::Vector3d Vector3;
typedef Eigen::Matrix3d Matrix3;

typedef double Type;
const Type eps = 1e-10;
#define PI 3.14159265358979323846

#ifdef USE_VTK
#include <vtk-9.0\vtkCellArray.h>
#include <vtk-9.0\vtkCellData.h>
#include <vtk-9.0\vtkDataSet.h>
#include <vtk-9.0\vtkDataSetAttributes.h>
#include <vtk-9.0\vtkDataObject.h>
#include <vtk-9.0\vtkDoubleArray.h>
#include <vtk-9.0\vtkGenericDataObjectReader.h>
#include <vtk-9.0\vtkGenericDataObjectWriter.h>
#include <vtk-9.0\vtkIdList.h>
#include <vtk-9.0\vtkLine.h>
#include <vtk-9.0\vtkLineSource.h>
#include <vtk-9.0\vtkMath.h>
#include <vtk-9.0\vtkNamedColors.h>
#include <vtk-9.0\vtkPointData.h>
#include <vtk-9.0\vtkPoints.h>
#include <vtk-9.0\vtkQuad.h>
#include <vtk-9.0/vtkSmartPointer.h>
#include <vtk-9.0\vtkTetra.h>
#include <vtk-9.0\vtkTriangle.h>
#include <vtk-9.0\vtkUnsignedCharArray.h>
#include <vtk-9.0\vtkUnstructuredGrid.h>


size_t ReadFileVtk(const size_t class_file_vtk, const std::string name_file_vtk, vtkSmartPointer<vtkUnstructuredGrid>& unstructuredgrid,
	vtkDataArray*& density, vtkDataArray*& absorp_coef, vtkDataArray*& rad_en_loose_rate, const bool is_print/*=false*/);

int GetAverageArea(int argc, char* argv[]);
int SetScalarDataVtkFromFile(int argc, char* argv[]);
int BuildHLLC_1dTime(int argc, char* argv[]);
int Trace2D(int argc, char* argv[]);

int Make1dFromTrace(const std::string& file_trace, const std::string& file_centers, const std::string& file_solve,
	const int max_iter);
int  RunMake1d(int argc, char* argv[]);


#endif //USE_VTK

int ReBuildNetgen2dToVTK(int argc, char* argv[]);
