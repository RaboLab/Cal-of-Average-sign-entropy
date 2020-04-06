#include "include.h"
#include "..\header\createHTML.h"
#include <string.h>
FILE * init() {
	FILE *fp;		//debug部分,检查输出，通过！
	fopen_s(&fp, "result.html", "w");

	fprintf(fp, "<!DOCTYPE html>\n \
		<html>\n \
		<head>\n \
		<meta charset = \"utf-8\">\n \
		<title>display the entroy</title>\n \
		</head>\n \
		<body>\n \
		<div>H1-Average-sign-entropy</div>\n \
		<div class=\"chartdiv\" id=\"chartdiv1\"></div>\n \
		<div>H2-Average-sign-entropy</div>\n \
		<div class=\"chartdiv\" id=\"chartdiv2\"></div>\n \
		<div>H3-Average-sign-entropy</div>\n \
		<div class=\"chartdiv\" id=\"chartdiv3\"></div>\n \
		<div>H4-Average-sign-entropy</div>\n \
		<div class=\"chartdiv\" id=\"chartdiv4\"></div>\n \
		<div>H5-Average-sign-entropy</div>\n \
		<div class=\"chartdiv\" id=\"chartdiv5\"></div>\n \
		</body>\n \
		<style>\n \
		.chartdiv{ \n \
		  width: 100 % ; \n \
		  height: 500px; \n \
		} \n \
		</style> \n \
		<script src = \"https://www.amcharts.com/lib/4/core.js\"></script> \n \
		<script src = \"https://www.amcharts.com/lib/4/charts.js\"></script> \n \
		<script src = \"https://www.amcharts.com/lib/4/themes/animated.js\"></script> \n \
		<script> \n \
		");
	return fp;
}
void writeData(FILE * fp, string chartdiv) {
	fprintf(fp, ("am4core.ready(function() {\n \
		am4core.useTheme(am4themes_animated);\n \
		var chart = am4core.create(\"" + chartdiv + "\", am4charts.XYChart);\n \
		chart.paddingRight = 20;\n \
		chart.data = [\n").c_str());
}
void endData(FILE * fp, string chartdiv)
{
	fprintf(fp, "];\n");
	fprintf(fp, "var categoryAxis = chart.xAxes.push(new am4charts.CategoryAxis());\n \
		categoryAxis.dataFields.category = \"year\";\n \
	categoryAxis.renderer.minGridDistance = 50;\n \
	categoryAxis.renderer.grid.template.location = 0.5;\n \
	categoryAxis.startLocation = 0.5;\n \
	categoryAxis.endLocation = 0.5;\n \
	var valueAxis = chart.yAxes.push(new am4charts.ValueAxis());\n \
	valueAxis.baseValue = 0;\n \
	var series = chart.series.push(new am4charts.LineSeries());\n \
	series.dataFields.valueY = \"value\";\n \
	series.dataFields.categoryX = \"year\";\n \
	series.strokeWidth = 2;\n \
	series.tensionX = 0.77;\n \
	var bullet = series.bullets.push(new am4charts.Bullet());\n \
	bullet.tooltipText = \"{valueY}\";\n \
	bullet.adapter.add(\"fill\", function(fill, target){\n \
		if (target.dataItem.valueY < 0) {\n \
			return am4core.color(\"#FF0000\");\n \
		}\n \
		return fill;\n \
	})\n \
		var range = valueAxis.createSeriesRange(series);\n \
	range.value = 0;\n \
	range.endValue = -1000;\n \
	range.contents.stroke = am4core.color(\"#FF0000\");\n \
	range.contents.fill = range.contents.stroke;\n \
	var scrollbarX = new am4charts.XYChartScrollbar();\n \
	scrollbarX.series.push(series);\n \
	chart.scrollbarX = scrollbarX;\n \
	chart.cursor = new am4charts.XYCursor();\n \
}); \n");
}
void fillData(FILE * fp, char * name, float value) {
	fprintf(fp, "{ \"year\": \"");
	fprintf(fp, name);
	fprintf(fp, "\", \"value\": ");
	fprintf(fp, "%f",value);
	fprintf(fp, " }, \n");
}
void close(FILE * fp) {
	fprintf(fp, "</script>\n");
	fclose(fp);
}