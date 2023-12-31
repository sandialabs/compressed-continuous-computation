// Copyright (c) 2015-2016, Massachusetts Institute of Technology
// Copyright (c) 2016-2017 Sandia Corporation

// This file is part of the Compressed Continuous Computation (C3) Library
// Author: Alex A. Gorodetsky 
// Contact: alex@alexgorodetsky.com

// All rights reserved.

// Redistribution and use in source and binary forms, with or without modification, 
// are permitted provided that the following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice, 
//    this list of conditions and the following disclaimer.

// 2. Redistributions in binary form must reproduce the above copyright notice, 
//    this list of conditions and the following disclaimer in the documentation 
//    and/or other materials provided with the distribution.

// 3. Neither the name of the copyright holder nor the names of its contributors 
//    may be used to endorse or promote products derived from this software 
//    without specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

//Code




#include <stdlib.h>
#include <stdio.h>

#include "CuTest.h"
#include "functest.h"

void RunAllTests(void) {
    
    printf("Running Test Suite: lib_funcs\n");

    CuString * output = CuStringNew();
    CuSuite * suite = CuSuiteNew();
    
    CuSuite * cheb = ChebGetSuite();
    CuSuite * leg  = LegGetSuite();
    CuSuite * herm = HermGetSuite();
    CuSuite * sp   = StandardPolyGetSuite();
    CuSuite * alg  = PolyAlgorithmsGetSuite();
    CuSuite * ser  = PolySerializationGetSuite();
    CuSuite * lelm = LelmGetSuite();
    CuSuite * celm = CelmGetSuite();    
    CuSuite * ll   = LinkedListGetSuite();
    CuSuite * pp   = PiecewisePolyGetSuite();
    CuSuite * pap  = PolyApproxSuite();
    CuSuite * preg = PolyRegressionSuite();
    CuSuite * kern = KernGetSuite();

    // polynomials
    CuSuiteAddSuite(suite, cheb);
    CuSuiteAddSuite(suite, leg);
    CuSuiteAddSuite(suite, herm);
    CuSuiteAddSuite(suite, sp);
    CuSuiteAddSuite(suite, alg);
    CuSuiteAddSuite(suite, ser);
    // linear elements
    CuSuiteAddSuite(suite, lelm);
    CuSuiteAddSuite(suite, celm);
    /* // other stuff */
    CuSuiteAddSuite(suite, ll);
    CuSuiteAddSuite(suite, pp);
    CuSuiteAddSuite(suite, pap);

    // Regression
    CuSuiteAddSuite(suite, preg);

    // Kernels
    CuSuiteAddSuite(suite, kern);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s \n", output->buffer);
    
    CuSuiteDelete(cheb);
    CuSuiteDelete(leg);
    CuSuiteDelete(herm);
    CuSuiteDelete(sp);
    CuSuiteDelete(alg);
    CuSuiteDelete(ser);
    CuSuiteDelete(lelm);
    CuSuiteDelete(celm);    
    CuSuiteDelete(ll);
    CuSuiteDelete(pp);
    CuSuiteDelete(pap);
    CuSuiteDelete(preg);
    CuSuiteDelete(kern);
        
    CuStringDelete(output);
    free(suite);
}

int main(void) {
    RunAllTests();
}
