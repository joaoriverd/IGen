library(ggplot2)
library(ggrepel)
library(scales)
library(extrafont)

plot_benchmark <- function (file_csv, sizesL, out_name) {
  dat <- read.csv(file_csv, header=FALSE)

  sizes           <- c(1:length(sizesL))
  vec_to_vec_f64i <- c(t(dat[1,1:ncol(dat)]))
  sc_to_vec_f64i  <- c(t(dat[2,1:ncol(dat)]))
  vec_to_vec_ddi  <- c(t(dat[3,1:ncol(dat)]))
  sc_to_vec_ddi   <- c(t(dat[4,1:ncol(dat)]))
  boost           <- c(t(dat[5,1:ncol(dat)]))
  gaol            <- c(t(dat[6,1:ncol(dat)]))
  filib           <- c(t(dat[7,1:ncol(dat)]))
  sc_to_sc_f64i   <- c(t(dat[8,1:ncol(dat)]))

  serie_0 <- data.frame(x=sizes, y=vec_to_vec_f64i, series="IGen_vv");
  serie_1 <- data.frame(x=sizes, y=sc_to_vec_f64i,  series="IGen_sv");
  serie_2 <- data.frame(x=sizes, y=sc_to_vec_ddi,   series="IGen_sv_dd");
  serie_3 <- data.frame(x=sizes, y=sc_to_sc_f64i,   series="IGen_ss");
  serie_4 <- data.frame(x=sizes, y=boost,           series="Boost");
  serie_5 <- data.frame(x=sizes, y=filib,           series="Filib");
  serie_6 <- data.frame(x=sizes, y=gaol,            series="Gaol");


  colorPalette <- c("#000000", "#000000", "#000000", "#000000", "#585858", "#585858", "#585858")
  shapePalette <- c(17, 20, 18, 15, 23, 21, 24)
  shapeSizes   <- c(0.5, 0.5, 1.0, 0.5, 0.5, 0.5, 0.5)

  plot_df <- do.call(rbind, list(serie_3, serie_1, serie_0, serie_2, serie_4, serie_5, serie_6));

  plotTitle <- paste(
    "interval ops / cycle",
    sep = "\n"
  )

  plot <- ggplot(plot_df, aes(x, y, colour=series, shape=series, size=series)) +
    theme_gray(base_family = "Carlito") +

    ggtitle(plotTitle) +

    xlab("Size") +

    scale_y_continuous() +
    scale_x_continuous(limits=c(head(sizes, n=1), tail(sizes, n=1)), breaks=sizes, label=sizesL) +

    geom_line() +
    geom_point(size = 2, fill = "white") +

    theme(
      panel.grid.major.x = element_blank(),
      panel.grid.minor.y = element_blank(),
      panel.grid.minor.x = element_blank(),
      #legend.position      = "below",
      legend.position      = "right",
      legend.text          = element_text(size=11),
      legend.title         = element_blank(),
      axis.title.y         = element_blank(),
      axis.line            = element_line(colour = "white"),
      axis.line.x          = element_line(colour = "black"),
      axis.text            = element_text(hjust=0.5, size=11, colour="black"),
      axis.title           = element_text(hjust=0.5, size=11),
      plot.title           = element_text(hjust=0, size=11)
    ) +

    scale_colour_manual(values=colorPalette) +
    scale_shape_manual (values=shapePalette) +
    scale_size_manual  (values=shapeSizes)

  k <- 1;
  ggsave(out_name, plot, width = 5.5/k, height = 4/k, device=cairo_pdf);
}

sizes_dft   <- c("16",  "32",  "64", "128", "256")
sizes_gemm  <- c("56", "168", "280", "392", "504", "616")
sizes_potrf <- c( "4",  "28",  "52", " 76", "100", "124")
sizes_ffnn  <- c("40",  "80", "120", "160", "200")
plot_benchmark("potrf/interval_perf.csv", sizes_potrf, "plot_potrf.pdf")
plot_benchmark("dft/interval_perf.csv"  , sizes_dft  , "plot_dft.pdf")
plot_benchmark("ffnn/interval_perf.csv" , sizes_ffnn , "plot_ffnn.pdf")
plot_benchmark("gemm/interval_perf.csv" , sizes_gemm , "plot_gemm.pdf")
