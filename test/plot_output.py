import matplotlib.pyplot as plt
import pandas as pd

if __name__ == '__main__':

    columns = ['time', 'antigen', 'capacity', 'antibody']
    df = pd.read_csv('output.csv', header=None, names=columns, index_col=False)
    df.set_index('time', inplace=True)
    print(df.head())

    fig, axs = plt.subplots(2, 1, figsize=(6, 6), sharex=True)

    df.antigen.plot(ax=axs[0])
    axs[0].set(yscale='log', title='antigen')

    df[['capacity', 'antibody']].plot(ax=axs[1])

    fig.set_tight_layout(True)

    plt.show()
